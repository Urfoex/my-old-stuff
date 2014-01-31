#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

void Prime( unsigned long countTo, unsigned long show);
short isPrime( unsigned long p);

void Prime( unsigned long countTo, unsigned long show){
  unsigned long i, count = 0;
  for ( i = 2; i <= countTo; i++ )
    if ( isPrime(i)) {
        ++count;
        (!(count%show))?printf ("pid %d : %ld \n", getpid(), i):0;
    }
}

short isPrime( unsigned long p){
  unsigned long s, d;
  s = ( unsigned long) sqrt(p) + 1;
  if ( p <  2 ) return 0;
  if ( p == 2 ) return 1;
  if ( p % 2 == 0 ) return 0;
  for ( d = 3; d <= s; d+=2 )
    if ( p % d == 0 ) return 0;
  return 1;
}

