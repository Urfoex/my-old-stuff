#include "prim_input.h"


int main( int argc, char** argv){
  unsigned short int sig_nr = 0;
  unsigned short int pidNR;
  char temp[10];
  pidNR = atoi( argv[1]);
  printf("<%s>\n",argv[1]);
  printf("proc: %ld : %hu\n", getpid(), pidNR);
  
  printf("%ld aktuelle Primzahl\n", SIGUSR1);
  printf("%ld Prim beu starten\n", SIGUSR2);
  printf("%ld aktuelle Sig-Zaehler\n", SIGINT);
  printf("%ld Ende\n", SIGQUIT);
  do{
    printf(">");
    scanf("%s", temp);
    printf("<%s>\n",temp);
    sig_nr = atoi( temp);
    switch( sig_nr){
      case SIGUSR1:
	sigsend( P_PID, pidNR, SIGUSR1);
	break;
      case SIGUSR2:
	sigsend( P_PID, pidNR, SIGUSR2);
	break;
      case SIGINT:
	sigsend( P_PID, pidNR, SIGINT);
	break;
      case SIGQUIT:
	sigsend( P_PID, pidNR, SIGQUIT);
	break;
      default:
	break;
    }
  }while(sig_nr != SIGQUIT);
  
  return 0;
}
