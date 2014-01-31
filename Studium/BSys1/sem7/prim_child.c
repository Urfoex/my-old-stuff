#include "prim_child.h"

int main( int argc, char* argv[]){
  unsigned short int i = 42;
  while( i) sigset( i--, sigCount);
  sigset( SIGUSR1, showPrimNow);
  sigset( SIGUSR2, restartPrim);
  sigset( SIGINT, showSigNr);
  sigset( SIGQUIT, quitPrim);
  
  printf ("pid %ld :\n", getpid());
  if( argc < 2){
    printf("need mor arguments: %ld\n", argc);
    return -1;
  }
  if( argc < 3)
    PrimeShort( atoi(argv[1]));
  else
    Prime( atoi(argv[1]), atoi(argv[2]));
  return 0;
}

void showPrimNow( int snr){
  ++sig_counter;
  printf("now: %ld\n", thePRIM);
};
 
void restartPrim( int snr){
  ++sig_counter;
  checkPrim = 2;
};

void showSigNr( int snr){
  ++sig_counter;
  printf("sigs: %ld\n", sig_counter);
};

void quitPrim( int snr){
  ++sig_counter;
  exit(0);
};

void sigCount( int snr){
  ++sig_counter;
};
