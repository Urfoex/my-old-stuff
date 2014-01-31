#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxInput 100
#define maxPf 100

struct element;
typedef struct element element;

struct element{
    element* next;
    char *chain;
};

void doInput( element* first);
void clearCl( element* first);
void printCl( element* first);
void searchCl( element* first, char* chain);

int main(int argc, char** argv) {
    element *first = ( element*)malloc( sizeof( first));
    element *last = ( element*)malloc( sizeof( last));
    first->next = 0;
    first->chain = 0;
    last = first;

    doInput( first);
    printCl( first->next);
    if(argc == 2) searchCl( first->next, argv[1]);
    clearCl( first->next);
    free(first);

    return 0;
}

void searchCl( element* first, char* chain){
    int i = 0;
    while( first){
        if( strstr( first->chain, chain))
            printf("occurrence %i: %s", i, first->chain);
        ++i;
        first = first->next;
    }
}

void printCl( element* first){
    do{
        printf("%s", first->chain);
        first = first->next;
    }while( first != 0);
}

void clearCl( element* first){
    element* temp;
    do{
        temp = first->next;
        free( first->chain);
        free( first);
        first = temp;
    }while(first);
}

void doInput( element* first){
    int counter = 0;
    unsigned char check = 0;
    char input[maxInput];
    element* temp = 0;
    while( fgets( input, sizeof(input), stdin) != NULL ){
        if( first->next == 0){
            first->next = (element*)malloc( sizeof(first));
            temp = first->next;
            temp->chain = (char*)calloc( strlen(input), sizeof(char));
            strcpy( temp->chain, input);
            temp->next = 0;
        }else{
            temp = first;

            while( strcmp( temp->next->chain, input) < 0){
                if( temp->next->next) temp = temp->next;
                else{
                    check = 1;
                    break;
                }
            }
            if( check){
                temp->next->next = (element*)malloc(sizeof(temp));
                temp = temp->next->next;
                temp->chain = (char*)calloc(strlen(input), sizeof(char));
                strcpy( temp->chain, input);
                temp->next = 0;
                check = 0;
            }else{
                element* temp2 = temp->next;
                temp->next = (element*)malloc(sizeof(temp));
                temp = temp->next;
                temp->chain = (char*)calloc(strlen(input), sizeof(char));
                strcpy( temp->chain, input);
                temp->next = temp2;
            }
        }
        ++counter;
    }
    printf("number of strings: %i\n", counter);
}

