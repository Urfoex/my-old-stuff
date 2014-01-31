/*
 * ============================================================================
 *
 *       Filename:  theWriter.cpp
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
#include <string>
#include <numeric>
#include <limits>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include "ioctl_esoteric.h"

using namespace std;

char* getMem( int mem){
    char* c = (char*)calloc(mem, sizeof(char));
    return c;
}

int main( int argc, char** argv){
    int fd = open( "/dev/esoteric", 0);
    if( fd < 0){
        cerr << "Could not open: " << fd << endl;
        return fd;
    }
    
    int end = 0;
    char *buffer = NULL;
    int mem = 0;
    char self;
    string msg;

    cout << "#Please close theWriter with CTRL+C\n";
    do{
        cout << "Options: SET to(l)ower, to(u)pper, (m)emory,\n";
        cout << "\t(a)scii, m(o)rse, no(s)pecial, m(e)ssage\n";
        cout << "\tGET memo(r)y, messa(g)e\n";
        cout << "End: (q)uit\n> ";
        cin >> self;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin.clear();

        switch(self){
        case 'l':
            ioctl( fd, SET_ESOTERIC_LOWER, NULL);
            break;
        case 'u':
            ioctl( fd, SET_ESOTERIC_UPPER, NULL);
            break;
        case 'm':
            cout << "How much memory you wish for?: ";
            cin >> mem;
            ioctl( fd, SET_ESOTERIC_MEMORY, mem);
            break;
        case 'a':
            ioctl( fd, SET_ESOTERIC_ASCII, NULL);
            break;
        case 'o':
            ioctl( fd, SET_ESOTERIC_MORSE, NULL);
            break;
        case 's':
            ioctl( fd, SET_ESOTERIC_NOSPECIAL, NULL);
            break;
        case 'e':
            cout << "Your message: ";
            getline(cin,msg);
            msg.append("\n\0");
            cout << "test. " << msg;
            ioctl( fd, SET_ESOTERIC_MEMORY, msg.length());
            ioctl( fd, SET_ESOTERIC_MESSAGE, msg.c_str());
            break;
        case 'r':
            cout << "mem: " << ioctl( fd, GET_ESOTERIC_MEMORY, NULL) << endl;
            break;
        case 'g':
            mem = ioctl( fd, GET_ESOTERIC_MEMORY, NULL);
            free(buffer);
            buffer = getMem( mem);
            ioctl( fd, GET_ESOTERIC_MESSAGE, buffer);
            cout << "MSG: " << buffer << endl;
            break;
        case 'q':
            end = 1;
            break;
        default:
            break;
        }
    }while(!end);

    free(buffer);
    cout << "--end--\n";

    return 0;
}