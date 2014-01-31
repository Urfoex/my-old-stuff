#include <unistd.h>

#include "empfanger.h"

int main( int argc, char** argv ) {
    char string[100];
    char pipename[3][100];
    signed short int pipeFlag[3];
    int pidPipeChild[3];
    struct stat statbuf;

    int rc, PID, availPipe = 3;
    signed short int transmitting = 3;
    signed short int i, j;
    int status;
    FILE* pipe;


    if( argc < 4){
        for( i = 0; i < argc - 1; ++i){
            strncpy( pipename[i], argv[ i + 1], sizeof( pipename[i]));
        }
        for( i = argc - 1; i < 3; ++i){
            printf("Sender-Nummer %d: ", i);
            fgets( pipename[i], sizeof( pipename[i]), stdin);
            pipename[i][ strlen( pipename[i]) - 1] = '\0';
        }
    }else{
        for( i = 0; i < argc - 1; ++i){
            strncpy( pipename[i], argv[ i + 1], sizeof( pipename[i]));
        }
    }

    for( i = 0; i < 3; ++i){
        pipeFlag[i] = 0;
        pidPipeChild[i] = 0;
        if( !strcmp( pipename[i], pipename[(i+1) % 3])){
            printf("gleiche Pipe nicht erlaubt: %s : %s\n", pipename[i], pipename[(i+1) % 3]);
            exit(-3);
        }
    }

    while( transmitting){
        transmitting = 3;
        for( i = 0; i < 3; ++i){
            rc = stat( pipename[i], &statbuf);
            if( rc < 0){
                --transmitting;
                pipeFlag[i] = 0;
                continue;
            }else{
                if( !S_ISFIFO( statbuf.st_mode)){
                    printf( "%s is no pipe\n", pipename[i]);
                    --transmitting;
                    pipeFlag[i] = 0;
                    continue;
                }else{
                    if( pipeFlag[i] == 0){
                        
                        PID = fork();
                        switch( PID){
                        case -1:
                            perror("switch");
                            break;
                        case 0:
                            fprintf( stderr, "child %d , pid: %d\n", i, getpid());
                            pipe = fopen( pipename[i], "r");
                            if( pipe == NULL){
                                perror("fopen");
                                exit(-i);
                            }

                            while( fgets( string, sizeof( string), pipe) != NULL){
                                printf( "pid: %d : pipe: %s : string: %s", getpid(), pipename[i], string);
                            }

                            fclose( pipe);
                            unlink( pipename[i]);
                            exit(i);

                            break;
                        default:
                            pipeFlag[i] = 1;
                            pidPipeChild[i] = PID;
                            break;
                        }
                        
                    }
                }
            }

            PID = waitpid( -1, &status, WNOHANG);
            if( PID > 0){
                fprintf( stderr, "status: pid(%d) %d : %d\n", PID, (status >> 8) & 0xFF, status & 0x7F);
                for( j = 0; j < 3; ++j){
                    if( PID == pidPipeChild[i]){
                        pidPipeChild[i] = 0;
                        pipeFlag[i] = 0;
                    }
                }
            }

        }
    }
    
    fprintf( stderr, "empfanger exit\n");
    return (EXIT_SUCCESS );
}

