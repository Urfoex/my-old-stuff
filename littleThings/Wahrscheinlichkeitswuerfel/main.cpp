/* 
 * File:   main.cpp
 * Author: kakarott
 *
 * Created on 4. Dezember 2009, 22:13
 */

#include <cstdlib>
#include <iostream>
#include "probability.h"
/*
 * 
 */
int main( int argc, char** argv ) {
    probability pro(1);
    pro.fill( USHRT_MAX*1000);
    pro.print();
    return (EXIT_SUCCESS );
}

