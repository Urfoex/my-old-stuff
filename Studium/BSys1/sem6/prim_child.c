#include "prim_child.h"

int main( int argc, char* argv[]){
  printf ("pid %ld :\n", getpid());
  if( argc < 3){
    printf("need mor arguments: %ld\n", argc);
    return -1;
  }
  Prime( atoi(argv[1]), atoi(argv[2]));

  return 0;
}
