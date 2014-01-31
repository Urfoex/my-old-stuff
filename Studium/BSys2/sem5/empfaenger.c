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
#include <sys/uio.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>


int main( int argc, char** argv){
    /* Variablen */
    char buf[100];
    int sockd,
        sockd2,
        l,
        rc,
        exitCode = 0;
    struct sockaddr_un uxaddr;
    struct iovec sv[1];
		 
    struct msghdr    msg;
    union {
	struct cmsghdr hdr;
        unsigned char    buf[CMSG_SPACE(sizeof(int))];
    } cmsgbuf;
    struct cmsghdr  *cmsg;

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
    

    /* Adr. initialisieren */
    uxaddr.sun_family = AF_UNIX;
    strcpy( uxaddr.sun_path, "sockunix");
    sockd = socket( AF_UNIX, SOCK_STREAM, 0);
    if( sockd < 0){
        perror("socket");
        exitCode = -1;
        goto errorLabel;
    }

    /* Socket verbinden */
    unlink( uxaddr.sun_path);
    rc = bind( sockd, (struct sockaddr*)&uxaddr, sizeof( uxaddr));
    if( rc < 0){
        perror("bind");
        exitCode = -2;
        goto errorLabel;
    }

    /* Auf Verbindung warten */
    rc = listen( sockd, 1);
    if( rc < 0){
        perror("listen");
        close(sockd);
        exitCode = -3;
        goto errorLabel;
    }

    /* Eintreffende Verbindung */
    fprintf( stderr, "waiting for client\n");
    sockd2 = accept( sockd, 0, 0);
    if( sockd2 < 0){
        perror("accept");
        exitCode = -4;
        goto errorLabel;
    }
    close( sockd);

    /* Dateinamen entgegen nehmen */
    l = read( sockd2, buf, sizeof( buf));
    if( l < 0){
        perror("read");
        close( sockd2);
        exitCode = -5;
        goto errorLabel;
    }
    fprintf( stderr, "new client: %s\n", buf);

    /* Datei Ãffnen */
    FILE* fp = fopen( buf, "r");
    int fd = 0;
    if( fp > 0){
        fd = fileno( fp);
        strcpy( buf, "ACK");
    }else{
        fprintf(stderr, "NAK\n");
        exitCode = 0;
        goto errorLabel;
    }
    fprintf( stderr, "sending: %s\n", buf);
    fprintf( stderr, "sending: %d\n", fd);
    

    /* Steuerdaten lesen */
    cmsg = CMSG_FIRSTHDR(&msg);
    
    cmsg->cmsg_len = CMSG_LEN(sizeof(int));
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    *(int *)CMSG_DATA(cmsg) = fd;

    /* Desk. senden */
    rc = sendmsg( sockd2, &msg, 0);
    if( rc < 0){
        perror("sendmsg");
        exitCode = -6;
        goto errorLabel;
    }

    fclose( fp);
    close( fd);

errorLabel:

    close( sockd2);
    unlink( uxaddr.sun_path );
    fprintf(stderr, "server ending\n");
    
    return exitCode;
}

