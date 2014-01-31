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


int ending = 0;
int check = 0;

void sigTermAction( int snr);
void sigChildAction( int snr);

int main( int argc, char** argv){

    sigset( SIGINT, sigTermAction);
    sigset( SIGCHLD, sigChildAction);

    char filename[100];

    int sockd, sockd2, l, rc;
    struct sockaddr_un uxaddr;
    char buf[100];

    uxaddr.sun_family = AF_UNIX;
    strcpy( uxaddr.sun_path, "sockunix");
    sockd = socket( AF_UNIX, SOCK_STREAM, 0);
    if( sockd < 0){
        perror("socket");
        exit(-1);
    }

    unlink( uxaddr.sun_path);
    rc = bind( sockd, (struct sockadr*)&uxaddr, sizeof( uxaddr));
    if( rc < 0){
        perror("bind");
        exit(-2);
    }

    rc = listen( sockd, 5);
    if( rc < 0){
        perror("listen");
        close(sockd);
        exit(-3);
    }

    int counter = 0;
    int pchld = 0;

    fprintf( stderr, "waiting for clients\n");
    do{
        sockd2 = accept( sockd, 0, 0);
        if( sockd2 < 0){
            if( errno == EINTR || check){
                check = 0;
                goto testForEnding;
            }else
                perror("accept");
        }
        ++counter;
        int pid = fork();
        switch( pid){
            case -1:
                perror("fork");
                exit(-4);
            case 0:
                close( sockd);

                l = read( sockd2, buf, sizeof( buf));
                if( l < 0){
                    perror("read");
                    close( sockd2);
                    exit(-4);
                }

                char filename[100];
                strcpy( filename, buf);

                fprintf( stderr, "new client: %s\n", filename);

                FILE* fp = fopen( buf, "r");
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

                l = write( sockd2, buf, strlen( buf) + 1);

                if( ending){
                    fprintf( stderr, "no new clients\n");
                    close( sockd2);
                    exit(2);
                }

                if( !strcmp( buf, "NAK")){    
                    fprintf(stderr, "waiting for respons\n");
                    l = read( sockd2, buf, sizeof( buf));
                    if( l < 0){
                        perror("read");
                        close( sockd);
                        exit(-5);
                    }
                    if( !strcmp( buf, "NAK")){ // NAK
                        fprintf( stderr, "not overwriting file\n");
                        close( sockd2);
                        exit(3);
                    }
                }else{
                    fprintf(stderr, "going to main\n");
                }
                unlink( filename);

                fprintf( stderr, "writing to file\n");

                while(  l = read( sockd2, buf, sizeof(buf))){
                    if( l > 0){
                        fprintf( stderr, "got: %s\n", buf);
                    }else{
                        perror("read");
                        if( l < 0)
                            continue;
                    }
                    fp = fopen( filename, "a");
                    fprintf( fp , "%s", buf);
                    fclose( fp);
                    sprintf( buf, "%d", l);
                    l = write( sockd2, buf, strlen( buf) + 1);
                    printf("got %s bytes\n", buf);
                }

                close( sockd2);

                fprintf( stderr, "closing client connection: %d\n", getpid());

                exit( getpid());
            default:
                close( sockd2);
                break;
        }

testForEnding:

        pchld = waitpid( 0, NULL, WNOHANG);
        if( pchld > 0){
            --counter;
            fprintf( stderr, "a client left, %d remaining\n", counter);
            goto testForEnding;
        }else{
            if( pchld < 0)
                perror("waitpid");
        }

    }while( !ending || counter);

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

void sigChildAction( int snr){
    check = 1;
}

