/* 
 * File:   die.cpp
 * Author: kakarott
 * 
 * Created on 4. Dezember 2009, 22:15
 */

#include "die.h"

die::die( ) {
    srand( time( 0));
}

die::die( const die& orig ) {
}

die::~die( ) {
}

const unsigned short int die::getNumber(){
    return NUMBER;
};

const unsigned short int die::getNumber( unsigned short int width){
    NUMBER = rand()%( width + 1);
    return NUMBER;
};
