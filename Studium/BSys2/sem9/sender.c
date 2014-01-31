#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

int main( int argc, char** argv){
    char filename[100];
    if( argc > 1){
        strcpy( filename, argv[1]);
    }else{
        printf("filename: ");
        fgets( filename, sizeof( filename), stdin);
        filename[ strlen(filename) - 1] = '\0';
    }

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

    rc = connect( sockd, (struct sockadr*)&uxaddr, sizeof( uxaddr));
    if( rc < 0){
        perror("connect");
        exit(-2);
    }


    fprintf( stderr, "connected, writing filename: %s\n", filename);

    l = write( sockd, filename, strlen( filename) + 1);
    if( l < 0){
        perror("write");
        close( sockd);
        exit(-3);
    }

    l = read( sockd, buf, sizeof( buf));
    if( l < 0){
        perror("read");
        close( sockd);
        exit(-4);
    }

    fprintf( stderr, "got: %s\n", buf);
    if( !strcmp( buf, "EM")){ // EM -> end of medium
        printf("server ending\n");
        close( sockd);
        exit(2);
    }
    if( !strcmp( buf, "NAK")){ // NAK
        printf("overwrite file?(y/n): ");
        fgets( filename, sizeof( filename), stdin);
        if( !strcmp( filename, "n\n")){
            fprintf( stderr, "aborting\n");
            l = write( sockd, buf, strlen( buf) + 1);
            close( sockd);
            exit(1);
        }

        fprintf( stderr, "getting ready\n");
        strcpy( buf, "ACK"); // ACK
        l = write( sockd, buf, strlen( buf) + 1);
    }
    while( fgets( buf, sizeof( buf), stdin)){
        l = write( sockd, buf, strlen( buf) + 1);
        fprintf( stderr, "wrote: %s\n", buf);
        rc = read( sockd, buf, sizeof( buf));
        printf("server got %s/%d bytes\n", buf, l);
    }
    close( sockd);
    fprintf(stderr, "client exited\n");

    return 0;
}
