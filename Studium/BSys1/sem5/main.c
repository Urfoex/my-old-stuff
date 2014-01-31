#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "prim0.c"


void child();
void parent();

int main( int argc, char* argv[]){
  pid_t pid;
  pid = fork();
  printf("pid: %d\n", getpid());
  switch( pid){
    case 0: /* child */
      printf("ppid: %d\n", getppid());
      child();
      break;
    case -1: /* error */
      perror("fork failed");
      exit;
    default: /* parent */
      parent();
      break;
  }
  return 0;
}

void child(){
  Prime( 5000000, 2000);
};

void parent(){
  pid_t pid;
  int status;
  Prime( 4000000, 2000);
  pid = wait( &status);
  printf("status: %d : %d\n", (status >> 8) & 0xFF, status & 0x7F);
};
