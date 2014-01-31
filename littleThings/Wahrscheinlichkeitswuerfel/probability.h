/* 
 * File:   probability.h
 * Author: kakarott
 *
 * Created on 4. Dezember 2009, 22:24
 */

#ifndef _PROBABILITY_H
#define	_PROBABILITY_H

#include <map>
#include <utility>
#include <climits>
#include <iostream>
#include "die.h"

class probability {
public:
    probability( );
    probability( unsigned short int width);
    probability( const probability& orig );
    void fill( unsigned long int quantity);
    void print();
    virtual ~probability( );
private:
    void fillMap();
    std::map<unsigned short int,unsigned long int> MapOfNumbers;
    die aDie;
    unsigned short int WIDTH;
};

#endif	/* _PROBABILITY_H */

