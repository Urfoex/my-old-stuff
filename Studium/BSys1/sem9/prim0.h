#ifndef PRIM0_H
#define PRIM0_H
  #include <stdio.h>
  #include <math.h>
  #include <sys/types.h>
  #include <unistd.h>
  
  unsigned long int thePRIM;
  unsigned long int checkPrim;
  unsigned long int countIsPrim;

  void Prime( unsigned long countTo, unsigned long show);
  void PrimeShort( unsigned long countTo);
  void PrimeShortZyklus( unsigned long countTo);
  short isPrime( unsigned long p);
#endif
