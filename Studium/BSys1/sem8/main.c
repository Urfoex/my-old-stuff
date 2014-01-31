#include "main.h"

int main( int argc, char** argv ) {
    char* FILENAME;
    if( argc < 2){
        FILENAME = (char*)calloc( 255, sizeof( char));
        fprintf(stderr,"no filename given\n");
        fprintf(stdout,"filename: ");
        fgets( FILENAME, 255, stdin);
        FILENAME[ strlen( FILENAME) - 1] = '\0';
    }else{
        FILENAME = argv[1];
    }
    pid_t PID1, PID2, pid;
    unsigned short int procs = 2;

    char** childArgv;
    char child1[] = "child1";
    char* string;
    char child2[] = "child2";

    struct timespec timer;
    timer.tv_sec = 1;
    timer.tv_nsec = 0;

    struct sigaction usr1Action;
    usr1Action.sa_handler = usr1;
    usr1Action.sa_flags = 0;
    sigemptyset( &usr1Action.sa_mask);

    sigaction( SIGUSR1, &usr1Action, NULL);

    PID1 = fork();

    switch( PID1){

    case -1:
        perror("pid1");
        return (EXIT_FAILURE);
    case 0:
        childArgv = (char**)calloc( 3, sizeof(char*));

        childArgv[0] = child1;
        childArgv[1] = FILENAME;
        childArgv[2] = NULL;

        execv(childArgv[0], childArgv);

        perror("execv 1");
        return (EXIT_FAILURE);
    default:
         pause();
         break;
    }

    PID2 = fork();

    switch( PID2){
    case -1:
        perror("pid2");
        return (EXIT_FAILURE);
    case 0:
        childArgv = (char**)calloc( 4, sizeof(char*));
        string = (char*)calloc( 10, sizeof(char));
        sprintf( string, "%d", PID1);
        childArgv[0] = child2;
        childArgv[1] = FILENAME;
        childArgv[2] = string;
        childArgv[3] = NULL;

        execv(childArgv[0], childArgv);

        perror("execv 2");
        kill( PID1, SIGUSR2);
        return (EXIT_FAILURE);
    default:
        break;
    }

    procs = 2;

    do{
        int status;
        pid = waitpid( -1, &status, 0);
        if( pid){
            fprintf( stderr, "status: pid(%d) %d : %d\n", pid, (status >> 8) & 0xFF, status & 0x7F);
            --procs;
        }
    }while(procs);

    return (EXIT_SUCCESS );
}

void usr1( int snr){

}
