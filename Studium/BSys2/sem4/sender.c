/*
 * =====================================================================================
 *
 *       Filename:  sender.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29.03.10 15:15:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Manuel Bellersen (mbellers), manuel.bellersen@stud.htwk-leipzig.de
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>

#include "steuerinfo.h"


int main( int argc, char** argv){
    /* Variablen festlegen */
    int sockd;
    int l,
        flags = 0,
        rc;
    struct sockaddr_un srvadr, 
                       cladr;
    char eab[100];

    struct stat buf;
    char fname[20];
    char pid[7];

    /* Adressstruktur bereitstellen */
    srvadr.sun_family = AF_UNIX;
    strcpy( srvadr.sun_path, "sockdram1");
    
    /* dyn. Filename festlegen */
    sprintf( pid, "%d", getpid());
    strcpy( fname, "46958.");
    strcat( fname, pid);

    fprintf( stderr, "own pipe: %s\n", fname);
    strcpy( cladr.sun_path, fname);
    fprintf( stderr, "own pipe: %s\n", cladr.sun_path);
    cladr.sun_family = AF_UNIX;

    /* Socket einrichten */
    sockd = socket( AF_UNIX, SOCK_DGRAM, 0);
    if( sockd < 0){
        perror("socket");
        exit(-1);
    }

    /* Socket mit Adr.-Str. verbinden */
    rc = bind( sockd, (struct sockaddr*)&cladr, sizeof(cladr));
    if( rc < 0){
        perror("bind");
        exit(-2);
    }

//    /* Anforderung an Server */
//    rc = sendto( sockd, eab, sizeof( eab), flags, (struct sockaddr*)&srvadr, sizeof( srvadr));
//    if( rc < 0){
//        perror("sendto");
//	goto errorLabel;
//    }
//
//    /*Antwort von Server */
//    rc = recvfrom( sockd, eab, sizeof( eab), flags, NULL, NULL);
//    if( rc < 0){
//        perror("recvfrom");
//	goto errorLabel;
//    }

    setMaster();
    setControl();
    setData();

    /* Start setzten */
    strcpy( control.buf, "\002"); /* STX */
    strcpy( data.buf, pid);

    control.len = strlen( control.buf) + 1;
    data.len = strlen( data.buf) + 1;
    
    /* STX senden */
    fprintf( stderr, "sending STX\n");
    /* Anforderung an Server */
    rc = sendto( sockd, control.buf, control.maxlen, flags,
            (struct sockaddr*)&srvadr, sizeof( srvadr));
    if( rc < 0){
        perror("sendto");
        goto errorLabel;
    }

    /* auf Antwort warten */
    fprintf( stderr, "waiting to receive ACK / NAK\n");
    /*Antwort von Server */
    rc = recvfrom( sockd, control.buf, control.maxlen, flags, NULL, NULL);
    if( rc < 0){
        perror("recvfrom");
        goto errorLabel;
    }
    if( !strcmp( control.buf, "\021")){ /* NAK */
        fprintf( stderr, "...got NAK\nserver ending...\n");      
        goto errorLabel;
    }
    fprintf( stderr, "e: %d\n", control.buf[0]);


    /* Eingabe starten und senden */
    fprintf( stderr, "...got ACK\ngetting input:\n");
    while( fgets( data.buf, data.maxlen - 1, stdin)){
        data.len = strlen( data.buf) + 1;
        /* Anforderung an Server */
        rc = sendto( sockd, data.buf, data.len, flags,
                (struct sockaddr*)&srvadr, sizeof( srvadr));
        if( rc < 0){
            perror("sendto");
        }
    }

    strcpy( control.buf, "\003"); /* ETX */
    control.len = strlen( control.buf) + 1;
    
    fprintf( stderr, "ending with sending ETX\n");
    /* Anforderung an Server */
    rc = sendto( sockd, control.buf, control.maxlen, flags,
            (struct sockaddr*)&srvadr, sizeof( srvadr));
    if( rc < 0){
        perror("sendto");
        goto errorLabel;
    }

errorLabel:
    unsetControl();
    unsetData();
    unsetMaster();

    /* Komm. beenden */
    close( sockd);
    unlink( cladr.sun_path);

    return 0;
}
