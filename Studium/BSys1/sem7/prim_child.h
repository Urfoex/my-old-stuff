#ifndef PRIM_CHILD_H
#define PRIM_CHILD_H
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <signal.h>
  #include "prim0.h"
  
  unsigned long int sig_counter = 0;
  
  extern unsigned long int thePRIM;
  extern unsigned long int checkPrim;
  
  void showPrimNow( int snr);
  void restartPrim( int snr);
  void showSigNr( int snr);
  void quitPrim( int snr);
  void sigCount( int snr);
#endif
