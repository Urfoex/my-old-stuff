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
#include <errno.h>
#include <string.h>

#include "steuerinfo.h"


int main( int argc, char** argv){
    struct stat buf;
    char fname[20];
    char pid[7];
    sprintf( pid, "%d", getpid());
    strcpy( fname, "46958.");
    strcat( fname, pid);
    strcat( fname, ".pipe");

    fprintf( stderr, "own pipe: %s\n", fname);

    int rc = stat( fname, &buf);
    int flags = 0;
    mode_t mode = 0777;

    if( rc < 0){
        if( errno != ENOENT){
            perror("stat(own pipe)");
            return -1;
        }
        rc = mkfifo( fname, mode);
        if( rc < 0){
            perror("mkfifo(own pipe)");
            return -2;
        }
    }else{
        if( !S_ISFIFO( buf.st_mode)){
            printf("%s is no pipe \n", fname);
            return -3;
        }
    }

    setMaster();
    setControl();
    setData();

    rc = stat( MASTERPIPE, &buf);

    if( rc < 0){
        if( errno != ENOENT){
            perror("stat(MASTERPIPE)");
            goto errorLabel;
        }
        rc = mkfifo( MASTERPIPE, mode);
        if( rc < 0){
            perror("mkfifo(MASTERPIPE)");
            goto errorLabel;
        }
    }else{
        if( !S_ISFIFO( buf.st_mode)){
            printf("%s is no pipe \n", MASTERPIPE);
            goto errorLabel;
        }
    }

    /* MasterPipe fuer schreiben oeffnen */
    FILE* masterPipe = fopen( MASTERPIPE, "w");
    if( !masterPipe ){
        perror("fopen()");
        goto errorLabel;
    }
    int fd_mP = fileno( masterPipe);

    strcpy( control.buf, "\002"); /* STX */
    strcpy( data.buf, pid);

    control.len = strlen( control.buf) + 1;
    data.len = strlen( data.buf) + 1;
    
    /* STX senden */
    fprintf( stderr, "sending STX\n");
    rc = putmsg( fd_mP, &control, &data, 0);
    if( rc){
        perror("putmsg");
        goto errorLabel;
    }


    /* eigene Pipe oeffnen */
    FILE* ownPipe = fopen( fname, "r");
    if( !ownPipe){
        perror("fopen()");
        goto errorLabel;
    }
    int fd_oP = fileno( ownPipe);
    
    /* auf Antwort warten */
    fprintf( stderr, "waiting to receive ACK / NAK\n");
    rc = getmsg( fd_oP, &control, NULL, &flags);
    if( rc < 0){
        perror("getmsg");
        goto errorLabel;
    }
    if( !strcmp( control.buf, "\021")){ /* NAK */
        fprintf( stderr, "...got NAK\nserver ending...\n");      
        goto errorLabel;
    }
    fprintf( stderr, "e: %d\n", control.buf[0]);

    fclose( ownPipe);

    /* Eingabe starten und senden */
    strcpy( control.buf, pid);
    control.len = strlen( control.buf) + 1;
    fprintf( stderr, "...got ACK\ngetting input:\n");
    while( fgets( data.buf, data.maxlen - 1, stdin)){
        data.len = strlen( data.buf) + 1;
        putmsg( fd_mP, &control, &data, 0);
    }

    strcpy( control.buf, "\003"); /* ETX */
    strcpy( data.buf, pid);

    control.len = strlen( control.buf) + 1;
    data.len = strlen( data.buf) + 1;
    
    fprintf( stderr, "ending with sending ETX\n");
    rc = putmsg( fd_mP, &control, &data, 0);
    if( rc){
        perror("putmsg");
        goto errorLabel;
    }

errorLabel:
    if( ownPipe){
        fclose( ownPipe);
        ownPipe = NULL;
    }
    unsetControl();
    unsetData();
    unsetMaster();

    unlink( fname);

    return 0;
}
