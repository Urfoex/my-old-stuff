/*
 * =====================================================================================
 *
 *       Filename:  empfaenger.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29.03.10 15:19:44
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
#include <sys/wait.h>
#include <errno.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>

#include "steuerinfo.h"

int ending = 0;

void sigTermAction( int snr);

int main( int argc, char** argv){
    sigset( SIGINT, sigTermAction);

    /* Variablen */
    int sockd,
        l,
        flags = 0,
        rc;
    struct sockaddr_un srvadr,
                       cladr;
    char eab[100];

    /* Adr. initialisieren */
    cladr.sun_family = AF_UNIX;
    srvadr.sun_family = AF_UNIX;
    strcpy( srvadr.sun_path, "sockdram1");
    unlink( srvadr.sun_path);

    /* Socket einrichten */
    sockd = socket( AF_UNIX, SOCK_DGRAM, 0);
    if( sockd < 0){
        perror( "socket");
        exit(-1);
    }

    /* Adr.str. und Socket verbinden */
    rc = bind( sockd, (struct sockaddr*)&srvadr, sizeof( srvadr));
    if( rc < 0){
        perror("bind");
        exit(-2);
    }

//    /* Empfangen */
//    l = sizeof( cladr);
//    rc = recvfrom( sockd, eab, sizeof( eab), flags, (struct sockaddr*)&cladr, &l);
//    if( rc < 0){
//        perror("recvfrom");
//    }
//
//    /* Senden */
//    rc = sendto( sockd, eab, sizeof( eab), flags, (struct sockaddr*)&cladr, sizeof(cladr));
//    if( rc < 0){
//        perror("sendto");
//    }

    struct stat buf;
    int counter = 0;

    mode_t mode = 0777;
    char filename[25];

    setMaster();
    setControl();
    setData();

    fprintf( stderr, "waiting for first client...\n");

    do{
        fprintf( stderr, "waiting for messages...\n");
        /* Empfangen */
        l = sizeof( cladr);
        rc = recvfrom( sockd, data.buf, data.maxlen, flags, (struct sockaddr*)&cladr, &l);
	data.len = rc;
	flags = 0;
        if( rc < 0){
            perror("recvfrom");
	    continue;
        }

        if( !strcmp( data.buf, "\002")){
            char tmp[20];
            strcpy( tmp, cladr.sun_path);
            strcat( tmp, ".log");
            fprintf(stderr, "R: %s\n", tmp);
            FILE* f_oP = fopen( tmp, "w");
            if( !f_oP){
                perror("fopen");
                continue;
            }
            int fd_oP = fileno( f_oP);
            fprintf( stderr, "new client found\n");

            if( !ending){
                fprintf( stderr, "adding client\n");
                ++counter;
                strcpy( control.buf, "\006");
                control.len = strlen( control.buf) + 1;
            }else{
                fprintf( stderr, "client denied\n");
                strcpy( control.buf, "\021");
                control.len = strlen( control.buf) + 1;
            }

            /* Senden */
            rc = sendto( sockd, control.buf, control.maxlen, flags, (struct sockaddr*)&cladr, sizeof(cladr));
            if( rc < 0){
                perror("sendto");
            }
            fclose( f_oP);   
            continue;
        }
        if( !strcmp( data.buf, "\003")){
            fprintf( stderr, "removing client\n");
            strcpy( filename, "cat ");
            strcat( filename, cladr.sun_path);
            strcat( filename, ".log");
            printf( "%s:\n", filename);
            system( filename); 
            --counter;
            continue;
        }
        fprintf( stderr, "data: %s\n", data.buf);
        fprintf( stderr, "clients: %d\n", counter);

        strcpy( filename, cladr.sun_path);
        strcat( filename, ".log");
        FILE* file = fopen( filename, "a+");
        if( file == NULL){
            perror("fopen");
        }else{
            fwrite( data.buf, data.len, 1, file);
            fclose( file);
        }
    }while( counter > 0 || !ending);
    fprintf( stderr, "no client anymore - quitting\n");

errorLabel:
    unsetControl();
    unsetData();
    unsetMaster();

    /* Ende */
    close( sockd);
    unlink( srvadr.sun_path);

    return 0;
}

void sigTermAction( int snr){
    fprintf( stderr, "ending...\n");
    ending = 1;
}

