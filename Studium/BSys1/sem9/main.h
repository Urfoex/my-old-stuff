#ifndef _MAIN_H
#define	_MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>

#include "prim0.h"

void alarmHandler( int snr);
extern unsigned long int countIsPrim;
extern unsigned long int checkPrim;
unsigned long int messwert[10];
unsigned short int messI;
unsigned long int PRIM_MAX = 2147483647;


#ifdef	__cplusplus
}
#endif

#endif	/* _MAIN_H */

