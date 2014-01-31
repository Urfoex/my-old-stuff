#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <poll.h>

int ending = 0;

void sigTermAction( int snr);

struct myInfoHeader{
    /**
    *   status:
    *   0 - neuer Client
    *   1 - auf Empfang
    */
    unsigned short status;  
    char filename[100];
};

int main( int argc, char** argv){

    sigset( SIGINT, sigTermAction);

    unsigned short int i = 0;
    int sockd, sockd2, l, rc;
    struct sockaddr_un uxaddr;
    char buf[100];
	
    int timeout = 10250;                // 10250 ms
    short clients = 3;                  // 3 Clients
    short connections = clients + 1;
	struct pollfd fds[connections];		// Deskriptorfeld
	struct myInfoHeader infoStatus[clients];    // Informationen über Filenamen und Stati
	for( i = 0; i < connections; ++i){          // Setzten der fds
        fds[i].fd = -1;
        fds[i].events = POLLIN;
    }	
    for( i = 0; i < clients; ++i){              // setzten der Informationen
        infoStatus[i].status = 0;
    }

    uxaddr.sun_family = AF_UNIX;
    strcpy( uxaddr.sun_path, "sockunix");
    sockd = socket( AF_UNIX, SOCK_STREAM, 0);   // socket anfordern
    if( sockd < 0){
        perror("socket");
        exit(-1);
    }

    unlink( uxaddr.sun_path);
    rc = bind( sockd, (struct sockadr*)&uxaddr, sizeof( uxaddr));   // socket verbinden
    if( rc < 0){
        perror("bind");
        exit(-2);
    }
    
    rc = listen( sockd, clients);               // Anzahl der Listeners setzten
    if( rc < 0){
        perror("listen");
        close(sockd);
        exit(-3);
    }
    
    int counter = clients;
    fds[0].fd = sockd;          // Eingang setzten

    fprintf( stderr, "waiting for clients\n");
    do{
        if( counter > 0 && fds[0].fd == -1 && !ending){     // Verbindung möglich -> socket wieder aufbauen
            sockd = socket( AF_UNIX, SOCK_STREAM, 0);
            if( sockd < 0){
                perror("socket");
                goto testForEnding;
            }
            fds[0].fd = sockd;       // weil clients möglich, frei halten
        
            unlink( uxaddr.sun_path);
            rc = bind( sockd, (struct sockadr*)&uxaddr, sizeof( uxaddr));
            if( rc < 0){
                perror("bind");
                goto testForEnding;
            }            
            rc = listen( sockd, clients);
            if( rc < 0){
                perror("listen");
                close(sockd);
                goto testForEnding;
            }
            
        }
        if( ending && fds[0].fd != -1){                     // Ende 
            close( sockd);
            fds[0].fd = -1;
        }
        if( counter == 0 && fds[0].fd != -1){               // kein Platz mehr frei
            close( sockd);
            fds[0].fd = -1;
        }
        rc = poll( fds, connections, timeout);              // auf Antworten warten
        if( rc < 0){                                        // Fehlerfall
            perror("poll");
            goto testForEnding;
        }
        if( rc == 0){                                       // timeout
            fprintf( stderr, "nothing\n");
            goto testForEnding;
        }
        if( rc > 0){                                        // Antworten erhalten
            if( (fds[0].fd > 0) && (fds[0].revents & POLLIN)){      // neuer Client
                sockd2 = accept( sockd, 0, 0);              // Akzeptieren
                if( sockd2 < 0){
                    if( errno == EINTR ){
                    }else{
                        perror("accept");
                    }
                    goto testForConnections;
                }
                --counter;                                  // ein Platz weniger
                if( counter == 0){      // alles besetzt
                    fds[0].fd = -1;
                    close( sockd);      // keine weitere Verbindungen erlauben !
                }
                for( i = 1; i < connections; ++i){          // suche freien Platz
                    if( fds[i].fd == -1){
                        fds[i].fd = sockd2;
                        break;
                    }
                }
            }
testForConnections:
            for( i = 1; i < connections; ++i){
                if( (fds[i].fd > 0) && (fds[i].revents & POLLIN)){      // neue Nachricht
                    l = read( fds[i].fd, buf, sizeof(buf));             // Empfangen
                    if( l < 0){                                         // Fehlerfall
                        perror("read");
                        close( fds[i].fd);
                        fds[i].fd = -1;
                        ++counter;
                        infoStatus[i-1].status = 0;
                        continue;
                    }
                    if( l == 0){                                        // Verbindungsende
                        close( fds[i].fd);
                        fds[i].fd = -1;
                        ++counter;
                        fprintf( stderr, "closing client connection: %s\n", infoStatus[i-1].filename);
                        infoStatus[i-1].status = 0;
                        continue;
                    }
//                    ...
                    FILE* fp;
                    switch( infoStatus[i-1].status){                    // Status überprüfen
                        case 0:                                         // neuer Client
                            strcpy( infoStatus[i-1].filename, buf);
                            fprintf( stderr, "new client: %s\n", infoStatus[i-1].filename);
            
                            fp = fopen( buf, "r");
                            if( fp > 0){
                                strcpy( buf, "NAK"); // NAK
                            }else{
                                strcpy( buf, "ACK"); // ACK
                            }
                            if( ending){
                                strcpy( buf, "EM"); // EM -> end of medium
                            }
                            fclose( fp);
            
                            fprintf( stderr, "sending: %s\n", buf);
            
                            l = write( fds[i].fd, buf, strlen( buf) + 1);   // Datei vorhanden ja/nein senden
            
                            if( ending){                                    // Server bereits am schließen
                                fprintf( stderr, "no new clients\n");
                                close( fds[i].fd);
                                fds[i].fd = -1;
                                ++counter;
                                continue;
                            }
            
                            if( !strcmp( buf, "NAK")){                      // Datei vorhanden
                                fprintf(stderr, "waiting for respons\n");
                                l = read( fds[i].fd, buf, sizeof( buf));
                                if( l < 0){                                 // Fehlerfall
                                    perror("read");
                                    close( fds[i].fd);
                                    fds[i].fd = -1;
                                    ++counter;
                                    continue;
                                }
                                if( !strcmp( buf, "NAK")){ // NAK           // Datei nicht überschreiben
                                    fprintf( stderr, "not overwriting file\n");
                                    close( fds[i].fd);
                                    fds[i].fd = -1;
                                    ++counter;
                                    continue;
                                }
                            }
                            fprintf(stderr, "going to main\n");
                            unlink( infoStatus[i-1].filename);              // Datei löschen, falls vorhanden
            
                            fprintf( stderr, "writing to file\n");
                            infoStatus[i-1].status = 1;
                            break;
                        case 1:                                             // Nachrichten empfangen und speichern
                            fprintf( stderr, "got: %s\n", buf);
                            fp = fopen( infoStatus[i-1].filename, "a");
                            fprintf( fp , "%s", buf);
                            fclose( fp);
                            sprintf( buf, "%d", l);
                            l = write( fds[i].fd, buf, strlen( buf) + 1);
                            printf("got %s bytes\n", buf);
                            break;
                        default:
                            break;
                    }
//                    ...
                }
            }
        }

testForEnding:

    unlink("blabla");   // Sinnlos, aber sonst klappt goto-Label nicht

    }while( !ending || counter < clients);

    close( sockd);
    close( sockd2);
    unlink( uxaddr.sun_path );
    fprintf(stderr, "server ending\n");
    
    return 0;
}

void sigTermAction( int snr){
    fprintf( stderr, "ending...\n");
    ending = 1;
}
