#include "main.h"

int main( int argc, char** argv){
  messI = 0;
  unsigned short int i = 0;
  unsigned long int sum = 0;
  unsigned long int mittelwert = 0;

  struct itimerval timer;
  timerclear( &timer.it_value);
  timerclear( &timer.it_interval);
  timer.it_value.tv_sec = 1;

  struct sigaction alarmAction;
  alarmAction.sa_handler = alarmHandler;
  alarmAction.sa_flags = 0;
  sigemptyset( &alarmAction.sa_mask);

  sigaction( SIGALRM, &alarmAction, NULL);
  for( i = 0; i < 10; ++i){
    setitimer( ITIMER_REAL, &timer, NULL);
    PrimeShort( PRIM_MAX);
  }

  for( i = 0; i < 10; ++i){
    sum += messwert[i];
    fprintf(stdout, "Messwert(%u) %lu\n", i, messwert[i]);
  }
  mittelwert = sum/10;
  fprintf( stdout, "Mittelwert: %lu\n", mittelwert);


  struct timeval tStart, tEnd;
  double tDiff[10], tSecDiff = 0, tUSecDiff = 0, tSum = 0, tMittel = 0;
  
  for( i = 0; i < 10; ++i){
    gettimeofday( &tStart, NULL);
    PrimeShortZyklus( mittelwert);
    gettimeofday( &tEnd, NULL);
    tSecDiff = difftime( tEnd.tv_sec, tStart.tv_sec);
    tUSecDiff = difftime( tEnd.tv_usec, tStart.tv_usec);
    tDiff[i] = tSecDiff*pow(10,6) + tUSecDiff;
  }
  
  for( i = 0; i < 10; ++i){
    tSum += tDiff[i];
    fprintf(stdout, "Zeit(%u) %lf\n", i, tDiff[i]);
  }

  tMittel = tSum/10.0;
  fprintf( stdout, "Zeit-Mittel: %lf\n", tMittel);
  return 0;
}

void alarmHandler( int snr){
  messwert[messI++] = countIsPrim;
  checkPrim = PRIM_MAX+1;
}
