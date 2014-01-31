/* 
 * File:   die.h
 * Author: kakarott
 *
 * Created on 4. Dezember 2009, 22:15
 */

#ifndef _DIE_H
#define	_DIE_H

#include <ctime>
#include <cstdlib>

class die {
public:
    die( );
    die( const die& orig );
    virtual ~die( );
    const unsigned short int getNumber();
    const unsigned short int getNumber( unsigned short int width);
private:
    unsigned short int NUMBER;

};

#endif	/* _DIE_H */

