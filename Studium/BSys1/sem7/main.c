#include "main.h"

int main( int argc, char* argv[]){
  unsigned long int nrOfArgs = 2;
  char** arguments = (char**)calloc( nrOfArgs, sizeof(char*));
  char pid1string[10];
  unsigned short int i = 0;
  
  for( i = 0; i < argc; ++i)
    arguments[i] = argv[i];  
  if( argc < nrOfArgs){
    printf("need more arguments: %ld\n", argc);

    for( i = argc; i < nrOfArgs; ++i){
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
      primChild( arguments[1]/*, arguments[2]*/);
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
      sprintf(pid1string,"%hu", pid1);
      printf("<%s>\n",pid1string);
      primIn( pid1string/*arguments[3], arguments[4]*/);
      exit(2);
    case -1: /* error */
      perror("fork failed");
      exit(-1);
    default: /* parent */
      break;
  }

  i = 2;

  do{
    int status;
    pid = waitpid( -1, &status, WNOHANG);
    if( pid){
      printf("status: pid(%d) %d : %d\n", pid, (status >> 8) & 0xFF, status & 0x7F);
      --i;
    }
  }while(i);
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

void primChild( char* arg1){
  printf("ppid: %d\n", getppid());
  char** argv = calloc( 3, sizeof( char*));
  char prim[] = "prim";
  argv[0] = prim;
  argv[1] = arg1;
  argv[2] = NULL;
  execv( argv[0], argv);
  perror("in primChild");
}

void primIn( char* arg1){
  printf("ppid: %d\n", getppid());
  char** argv = calloc( 3, sizeof( char*));
  char prim[] = "input";
  argv[0] = prim;
  argv[1] = arg1;
  printf("<%s>\n",argv[1]);
  argv[2] = NULL;
  execv( argv[0], argv);
  perror("in primIn");
}
