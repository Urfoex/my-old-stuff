#include "child1.h"

int main( int argc, char** argv ) {
    if( argc < 2){
        fprintf(stderr,"no filename\n");
        return (EXIT_FAILURE);
    }
    
    char* FILENAME = argv[1];
    char toRead[80];
    size_t num_read;
    struct timespec timer;
    timer.tv_sec = 1;
    timer.tv_nsec = 0;

    struct sigaction usr1Action;
    usr1Action.sa_handler = usr1;
    usr1Action.sa_flags = 0;
    sigemptyset( &usr1Action.sa_mask);

    sigaction( SIGUSR1, &usr1Action, NULL);

    struct sigaction usr2Action;
    usr2Action.sa_handler = usr2;
    usr2Action.sa_flags = 0;
    sigemptyset( &usr2Action.sa_mask);

    sigaction( SIGUSR2, &usr2Action, NULL);


    kill( getppid(), SIGUSR1);

    pause();

    fprintf( stderr, "file opening...\n");
    FILE* file = fopen( FILENAME, "r");
    if( !file){
        perror("file child1");
        return (EXIT_FAILURE);
    }

    do{
        num_read = fread( toRead, sizeof(char), sizeof( toRead), file);
        toRead[ num_read] = '\0';
        if( num_read != 0)
            printf("%s", toRead);
        if( ferror( stdin))
            continue;
    }while( num_read);
    fprintf(stderr, "file closing...\n");
    fflush( stdout);

    fclose(file);

    return (EXIT_SUCCESS );
}

void usr1( int snr){
    
}

void usr2( int snr){
    fprintf( stderr, "error from child2\n");
    exit(-1);
}
