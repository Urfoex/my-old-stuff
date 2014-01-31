#include "child2.h"

int main( int argc, char** argv ) {
    if( argc < 3){
        fprintf(stderr,"no filename or pid\n");
        return (EXIT_FAILURE);
    }

    pid_t PID1 = atoi( argv[2]);

    FILE*  file = fopen( argv[1],"a+");
    if( !file){
        perror("file child2");
        kill( PID1, SIGUSR2);
        return (EXIT_FAILURE);
    }
    fprintf( stderr, "file opened\n");
    char string[80];
    char* check;

    while(1){
        printf(">");
        check = fgets( string, sizeof(string), stdin);
        if( feof( stdin))
            break;
        fwrite( string, sizeof( char), strlen( string), file);
    };
 
    if( ferror( stdin))
        perror("read from stdin");
        
    fclose( file);
    fprintf( stderr, "file closed\n");

    kill( PID1, SIGUSR1);
    return (EXIT_SUCCESS );
}
