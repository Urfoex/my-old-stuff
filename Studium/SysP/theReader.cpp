/*
 * ============================================================================
 *
 *       Filename:  theReader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Manuel Bellersen , manuel.bellersen@stud.htwk-leipzig.de
 *        License:  GPLv3 or newer
 *
 * ============================================================================
 */

#include <iostream>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <csignal>
#include "ioctl_esoteric.h"

using namespace std;

int globVar = 0;

void sig(int snr){
    globVar = 1;
}

char* getMem( int mem){
    char* c = (char*)calloc(mem, sizeof(char));
    return c;
}

int main( int argc, char** argv){
    sigset( SIGINT, sig);
    int fd = open( "/dev/esoteric", 0);
    if( fd < 0){
        cerr << "Could not open: " << fd << endl;
        return fd;
    }
    
    char *buffer = NULL;
    int mem = 0;
    int mem2 = 0;

    cout << "#Please close theReader with CTRL+C\n";
    do{
        mem = ioctl( fd, GET_ESOTERIC_MEMORY, NULL);
        if( mem != mem2){
            free(buffer);
            buffer = getMem( mem);
            mem2 = mem;
        }
        ioctl( fd, GET_ESOTERIC_MESSAGE, buffer);
        cout << mem << ": " << buffer ;
        ioctl( fd, GET_ESOTERIC_WAITFORCHANGE, NULL);
    }while(!globVar);

    free(buffer);
    cout << "--end--\n";

    return 0;
}