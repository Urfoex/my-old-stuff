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
#include <pthread.h>
#include <semaphore.h>

int ending = 0;
int check = 0;

pthread_t thread;
/* *
 * 0 - ID kann uebertragen werden
 * 1 - ID kann uebernommen werden
 * */
int flag = 0;
pthread_mutex_t mutex;

void sigTermAction( int snr);
void sigChildAction( int snr);


/* *
 * Thread-Behandlungs-Funktion
 * */
void* thrdFkt( void* p){
    /* *
     * Uebernahme des Socketdeskriptors
     * */
    int sockd2 = 0;
    if( p == NULL){
        fprintf( stderr, "no desk\n");
        goto pError;
    }
    int* _t = p;
    sockd2 = *_t;
    fprintf( stderr, "having socket: %d\n", sockd2);

    /* *
     * Signale blockieren
     * */
    sigset_t neu;
    sigemptyset( &neu);
    sigaddset( &neu, SIGINT);
    sigaddset( &neu, SIGUSR1);
    pthread_sigmask( SIG_BLOCK, &neu, NULL);

    /* *
     * Variablen
     * */
    int l;
    char buf[100];


    l = read( sockd2, buf, sizeof( buf));
    if( l < 0){
        perror("read");
        close( sockd2);
        goto pError;
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
        goto pError;
    }

    if( !strcmp( buf, "NAK")){    
        fprintf(stderr, "waiting for respons\n");
        l = read( sockd2, buf, sizeof( buf));
        if( l < 0){
            perror("read");
            goto pError;
        }
        if( !strcmp( buf, "NAK")){ // NAK
            fprintf( stderr, "not overwriting file\n");
            close( sockd2);
            goto pError;
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

pError:
    close( sockd2);
    free( p);

    fprintf( stderr, "closing client connection \n");

    /* *
     * Uebgerbage der Thread-ID
     * */
    int fertig = 0;
    while( !fertig){
        pthread_mutex_lock( &mutex);
        if( flag == 0){
            thread = pthread_self();
            fprintf( stderr, "ending thread: %d\n", thread);
            flag = 1;
            fertig = 1;
        }
        pthread_mutex_unlock( &mutex);
        if( !fertig){
            sleep( 1);
        }
    }
    /* *
     * Signal an Prozess senden
     * */
    kill( getpid(), SIGUSR1);

    fprintf( stderr, "end of %d\n", pthread_self());
    return;
}

int main( int argc, char** argv){

    sigset( SIGINT, sigTermAction);
    sigset( SIGUSR1, sigChildAction);

    char filename[100];

    int sockd, l, rc;
    int* sockd2;
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

    pthread_t thrid;
    pthread_attr_t attr;
    void* args;

    fprintf( stderr, "waiting for clients\n");
    do{    
        if( ending){
            goto testForEnding;
        }
        sockd2 = (int*)malloc( sizeof(int));
        *sockd2 = accept( sockd, 0, 0);
        if( *sockd2 < 0){
            if( errno == EINTR || check){
                check = 0;
                goto testForEnding;
            }else
                perror("accept");
        }
        ++counter;

        /* *
         * Thread erstellen
         * */
        pthread_t thrid;
        rc = pthread_create( &thrid, NULL, thrdFkt, sockd2);
        if( rc != 0){
            strerror(rc);
        }
        fprintf( stderr, "created thread: %d\n", thrid);

testForEnding:
        if( ending){
           close( sockd);
        }

        /* *
         * Schauen, ob ein Thread fertig ist
         * */
        pthread_mutex_lock( &mutex);
        if( flag == 1){
            fprintf( stderr, "thread ended: %d\n", thread);
            pthread_join( thread, NULL);
            flag = 0;
            --counter;
            fprintf( stderr, " connections left: %d\n", counter);
        }
        pthread_mutex_unlock( &mutex);
        if( ending && counter){
            fprintf( stderr, " end: %d , connections: %d\n", ending, counter);
            sleep(1);
        }

    }while( !ending || counter);

    close( sockd);
    close( *sockd2);
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

