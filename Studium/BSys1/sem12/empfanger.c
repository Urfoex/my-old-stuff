#include "empfanger.h"

int main( int argc, char** argv ) {
    char string[100];
    char pipename[3][100];
    signed short int pipeFlag[3];
    int fdPipe[3];
    struct stat statbuf;

    int rc, flags;
    signed short int transmitting = 3;
    signed short int i;
    FILE* pipe[3];

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
        fdPipe[i] = 0;
        pipe[i] = NULL;
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
                        pipe[i] = fopen( pipename[i], "r");
                        if( pipe[i] == NULL)
                            perror("fopen");
                        fdPipe[i] = fileno( pipe[i]);
                        fprintf( stderr, "fileno: %d\n", fdPipe[i]);
                        flags = fcntl( fdPipe[i], F_GETFL);
                        flags |= O_NONBLOCK;
                        rc = fcntl( fdPipe[i], F_SETFL, flags);
                        pipeFlag[i] = 1;
                    }
                    if( pipeFlag[i] == 1){
                        if( fgets( string, sizeof( string), pipe[i]) != NULL){
                            printf( "id: %d : pipe: %s : string: %s", i, pipename[i], string);
                        }else{
                            if( errno == EAGAIN){
                                errno = 0;
                                continue;
                            }
                            fprintf( stderr, "errno: %d : %s\n", errno, strerror( errno));
                            fprintf( stderr, "close pipe: %d\n", i);
                            fclose( pipe[i]);
                            unlink( pipename[i]);
                            pipeFlag[i] = 0;
                        }
                    }
                }
            }
        }
    }
    
    fprintf( stderr, "empfanger exit\n");
    return (EXIT_SUCCESS );
}

