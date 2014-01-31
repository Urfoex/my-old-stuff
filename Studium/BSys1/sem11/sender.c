#include <unistd.h>

#include "sender.h"

int main( int argc, char** argv ) {
    char string[100];
    char pipename[100];

    mode_t mode = 0644;
    int rc;

    if( argc < 2){
        printf("Sender-Nummer: ");
        fgets( pipename, sizeof( pipename), stdin);
        pipename[ strlen( pipename) - 1] = '\0';
    }else{
        strncpy( pipename, argv[1], sizeof( pipename));
    }
    
    rc = mkfifo( pipename, mode);
    if( rc < 0){
        perror("mkfifo");
        exit(-1);
    }

    FILE* pipe = fopen( pipename, "w");

    while( fgets( string, sizeof( string), stdin) != NULL){
        fputs( string, pipe);
        fflush( pipe);
    }

    fclose( pipe);

    return (EXIT_SUCCESS );
}

