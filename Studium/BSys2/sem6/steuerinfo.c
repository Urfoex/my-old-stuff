/*
 * =====================================================================================
 *
 *       Filename:  steuerinfo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29.03.10 15:20:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Manuel Bellersen (mbellers), manuel.bellersen@stud.htwk-leipzig.de
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdio.h>

#include "steuerinfo.h"

void setMaster(){
    char tmp[] = "46958.master.pipe";
    MASTERPIPE = (char*)calloc( strlen( tmp) + 1, sizeof(char));
    strcpy( MASTERPIPE, tmp);
    MASTERMODE = 0777;
}

void unsetMaster(){
    free( MASTERPIPE);
}

void setControl(){
    char* buffer = (char*)calloc( 10, sizeof( char));
    control.buf = buffer;
    control.maxlen = 10;
    fprintf( stderr, "control: %d\n", control.maxlen);
}

void unsetControl(){
    free( control.buf);
}

void setData(){
    char* buffer = (char*)calloc( 80, sizeof( char));
    data.buf = buffer;
    data.maxlen = 80;
    fprintf( stderr, "data: %d\n", data.maxlen);
}

void unsetData(){
    free( data.buf);
}
