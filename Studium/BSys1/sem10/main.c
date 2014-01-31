#include "main.h"

int main( int argc, char** argv){
    char string[100];

    int childPID;
    int pipe1_child1[2];
    int pipe2_child1[2];

    if( pipe( pipe1_child1)){
        perror("pipe1_c1");
        exit(-11);
    }
    if( pipe( pipe2_child1)){
        perror("pipe2_c2");
        exit(-21);
    }

    childPID = fork();

    switch( childPID){
    case -1:
        perror("fork1");
        exit(-1);
    case 0:
        close( pipe1_child1[0]);
        close( pipe2_child1[1]);

        char child1[] = "child1";

        do{
            read( pipe2_child1[0], string, sizeof(string));
            if( !strcmp( string, child1)){
                fprintf(stdout,"child1 < ");
                fgets( string, sizeof(string), stdin);
                if( feof( stdin))
                    break;
                write( pipe1_child1[1], string, strlen(string) + 1);
            }else{
                char wrong[] = "wrong input\n";
                write( pipe1_child1[1], wrong, strlen(wrong) + 1);
            }
        }while( ! feof(stdin));

        fprintf( stderr, "child1 end\n");

        close( pipe1_child1[1]);
        close( pipe2_child1[0]);        

        exit(1);
        break;
    default:
        close( pipe1_child1[1]);
        close( pipe2_child1[0]);
        break;
    }

    int pipe1_child2[2];
    int pipe2_child2[2];

    if( pipe( pipe1_child2)){
        perror("pipe1_c2");
        exit(-12);
    }
    if( pipe( pipe2_child2)){
        perror("pipe2_c2");
        exit(-22);
    }

    childPID = fork();

    switch( childPID){
    case -1:
        perror("fork2");
        exit(-2);
    case 0:
        close( pipe1_child2[0]);
        close( pipe2_child2[1]);
        
        char child2[] = "child2";

        do{
            read( pipe2_child2[0], string, sizeof(string));
            if( !strcmp( string, child2)){
                fprintf(stdout,"child2 < ");
                fgets( string, sizeof(string), stdin);
                if( feof( stdin))
                    break;
                write( pipe1_child2[1], string, strlen(string) + 1);
            }else{
                char wrong[] = "wrong input\n";
                write( pipe1_child2[1], wrong, strlen(wrong) + 1);
            }
        }while( ! feof(stdin));

        fprintf( stderr, "child2 end\n");

        close( pipe1_child2[1]);
        close( pipe2_child2[0]);

        exit(2);
        break;
    default:
        close( pipe1_child2[1]);
        close( pipe2_child2[0]);
        break;
    }

    char child[2][7] = { "child1" , "child2"};

    int proc = 3;

    while( proc){
        if( proc == 1 || proc  == 3){
            write( pipe2_child1[1], child[0], strlen( child[0]) + 1);
            if( read( pipe1_child1[0], string, sizeof( string)) > 0)
                printf( "c1: %s", string);
            else
                proc -= 1;
        }
        if( proc == 2 || proc == 3){
            write( pipe2_child2[1], child[1], strlen( child[1]) + 1);
            if( read( pipe1_child2[0], string, sizeof( string)) > 0)
                printf( "c2: %s", string);
            else
                proc -= 2;
        }
    }

    fprintf( stderr, "closing main\n");

    close( pipe1_child1[0]);
    close( pipe1_child2[0]);
    close( pipe2_child1[1]);
    close( pipe2_child2[1]);

    proc = 2;

    do{
        int status;
        childPID = waitpid( -1, &status, 0);
        if( childPID){
            fprintf( stderr, "status: pid(%d) %d : %d\n", childPID, (status >> 8) & 0xFF, status & 0x7F);
            --proc;
        }
    }while(proc);

    return 0;
}
