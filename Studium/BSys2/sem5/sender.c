#ifdef sun
    #ifndef _XOPEN_SOURCE 
        #define _XOPEN_SOURCE
    #endif
    #ifndef _XOPEN_SOURCE_EXTENDED 
        #define _XOPEN_SOURCE_EXTENDED 1
    #endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>
    
  
int main( int argc, char** argv){
    /* Variablen */
    char buf[100];
    char filename[100];
    int sockd,
        rc;
    struct sockaddr_un uxaddr;
    struct iovec sv[1];
    
    struct msghdr    msg;
    struct cmsghdr  *cmsg;
    union {
        struct cmsghdr hdr;
	unsigned char    buf[CMSG_SPACE(sizeof(int))];
    } cmsgbuf;

    memset(&msg, 0, sizeof(msg));
    msg.msg_control = &cmsgbuf.buf;
    msg.msg_controllen = sizeof(cmsgbuf.buf);
	   
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = sv;
    msg.msg_iovlen = 1;
    msg.msg_flags = 0;

    sv[0].iov_base = buf;
    sv[0].iov_len = sizeof(buf);

    /* Dateiname */
    if( argc > 1){
        strcpy( filename, argv[1]);
    }else{
        printf("filename: ");
        fgets( filename, sizeof( filename), stdin);
        filename[ strlen(filename) - 1] = '\0';
    }

    /* Adr.str. initialisieren */
    uxaddr.sun_family = AF_UNIX;
    strcpy( uxaddr.sun_path, "sockunix");
    sockd = socket( AF_UNIX, SOCK_STREAM, 0);
    if( sockd < 0){
        perror("socket");
        exit(-1);
    }

    /* Verbinden */
    rc = connect( sockd, (struct sockaddr*)&uxaddr, sizeof( uxaddr));
    if( rc < 0){
        perror("connect");
        exit(-2);
    }

    /* Dateiname Ãbergeben */
    fprintf( stderr, "connected, writing filename: %s\n", filename);
    rc = write( sockd, filename, strlen( filename) + 1);
    if( rc < 0){
        perror("write");
        close(sockd);
        exit(-3);
    }
    fprintf( stderr, "Waiting for descriptor...\n");

    /* Desk. empfangen */
    rc = recvmsg( sockd, &msg, 0);
    if( rc < 0){
        perror("recvmsg");
        close( sockd);
        exit(-4);
    }
    if( rc == 0){
        fprintf(stderr, "Keine Datei\n");
        close( sockd);
        exit(0);
    }

    /* Empfangene Daten prÃ¼fen */
    fprintf(stderr, "Daten pruefen\n");
    cmsg = CMSG_FIRSTHDR(&msg);
    if( cmsg == NULL){
        fprintf(stderr, "cmsg\n");
        close( sockd);
        exit(-6);
    }

    /* Desk. entgegen nehmen */
    int fd = *(int*) CMSG_DATA(cmsg);
    if( fd == 0){
        fprintf( stderr, "no file\n");
        close( sockd);
        return 1;
    }

    /* Datei lesen und ausgeben */
    fprintf(stderr, "Daten ausgeben:\n");
    FILE* fp = fdopen( fd, "r");
    while( fgets( buf, sizeof( buf), fp)){
        printf("%s", buf);
    }
    
    /* Alles schliessen und beenden */
    fclose(fp);
    if( fd)
        close( fd);

    fprintf(stderr, "\nclient exited\n");

    close( sockd);

    return 0;
}
