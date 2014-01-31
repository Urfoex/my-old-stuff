#include "main.h"

int main( int argc, char* argv[]){
  char** arguments = (char**)calloc( 5, sizeof(char*));
  unsigned short int i = 0;
  for( i = 0; i < argc; ++i)
    arguments[i] = argv[i];  
  if( argc < 5){
    printf("need more arguments: %ld\n", argc);

    for( i = argc; i < 5; ++i){
      arguments[i] = (char*)calloc( 255, sizeof(char));
      printf("a%ld : ", i);
      fgets( arguments[i], 255, stdin);
    }

  };

  pid_t pid, pid1, pid2;
  pid1 = fork();
  printf("pid: %d\n", getpid());

  switch( pid1){
    case 0: /* child */
      child( arguments[1], arguments[2]);
      exit(1);
    case -1: /* error */
      perror("fork failed");
      exit(-1);
    default: /* parent */
      break;
  }
  pid2 = fork();
  printf("pid: %d\n", getpid());
  switch( pid2){
    case 0: /* child */
      child( arguments[3], arguments[4]);
      exit(2);
    case -1: /* error */
      perror("fork failed");
      exit(-1);
    default: /* parent */
      break;
  }

  int status;
  pid = wait( &status);
  printf("status: %d : %d\n", (status >> 8) & 0xFF, status & 0x7F);

  pid = wait( &status);
  printf("status: %d : %d\n", (status >> 8) & 0xFF, status & 0x7F);
  return 0;
}

void child( char* arg1, char* arg2){
  printf("ppid: %d\n", getppid());
  char** argv = calloc( 4, sizeof( char*));
  char prim[] = "prim";
  argv[0] = prim;
  argv[1] = arg1;
  argv[2] = arg2;
  argv[3] = NULL;
  execv( argv[0], argv);
  perror("in child");
}

