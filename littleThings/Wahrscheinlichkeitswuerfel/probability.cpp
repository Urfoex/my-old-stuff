/* 
 * File:   probability.cpp
 * Author: kakarott
 * 
 * Created on 4. Dezember 2009, 22:24
 */

#include "probability.h"

probability::probability( ) {
    WIDTH = 6;
    fillMap();
}

probability::probability( unsigned short int width){
    WIDTH = width;
    fillMap();
}

probability::probability( const probability& orig ) {
}

probability::~probability( ) {
}

void probability::fillMap(){
    for( unsigned long int i = 0; i <= WIDTH; ++i)
        MapOfNumbers.insert( std::pair<unsigned short int, unsigned long int>(i,0));
}

void probability::fill( unsigned long int quantity){
    if( quantity == ULONG_MAX)
        --quantity;
    for( unsigned long int i = 0; i < quantity; ++i)
        ++MapOfNumbers[aDie.getNumber( WIDTH)];
}

void probability::print(){
    unsigned long int count = 0;
    unsigned long int MIN = ULONG_MAX;
    unsigned long int MAX = 0;
    for( unsigned long int i = 0; i <= WIDTH; ++i){
        count += MapOfNumbers[i];
        if( MIN > MapOfNumbers[i])
            MIN = MapOfNumbers[i];
        if( MAX < MapOfNumbers[i])
            MAX = MapOfNumbers[i];
        std::cout << i << " " << MapOfNumbers[i] << std::endl;
    }
    std::cout << (long double)count/WIDTH << " " << (long double)MAX/MIN << std::endl;
    std::cout << "" << " " << MAX-MIN << std::endl;
    std::cout << "max:" << " " << MAX << std::endl;
    std::cout << "min:" << " " << MIN << std::endl;
}
