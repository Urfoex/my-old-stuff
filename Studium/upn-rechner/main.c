/*
// Programmierer: Manuel Bellersen
//                Matrikel 46958
//                Seminargruppe 08-INB-1
//
// Projektaufgabe 4: wissenschaftlicher UPN-Rechner
//                   double Zahlen
//                   zweistellige Operationen: + - * /
//                   einstellige Operationen: abs neg inv sqr sqrt
//                   weitere Befehle:
//                      'end' 'e': beendet den UPN-Rechner
//                      'print' 'p' : zeigt Kellerinhalt an
//                      'del'   'd' : loescht oberstes Kellerelement
//                      'clear' 'c' : loescht alle Kellerelemente
//                      'help' 'h' '?' : Ausgabe der Hilfe
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <float.h>

struct stack{
    struct stack* next;
    double number;
};

struct stack* masterStack;
const unsigned short int length = 256;  // ! bufferoverflow !

void addItem( const double var);
void deleteItem( );

void printStack( );
void printHelp( );

void Input( );

const signed char isValidSingleOperation( const char* string);
void absolute( );
void negative( );
void inverse( );
void square( );
void squareroot( );

const signed char isValidDoubleOperation( const char* string);
void addition( );
void subtraction( );
void multiplication( );
void division( );


void addItem( const double var){
    struct stack* temp = (struct stack*) malloc( sizeof( struct stack));
    if( masterStack == NULL){
        masterStack = temp;
        masterStack->number = var;
        masterStack->next = NULL;
        return;
    }
    temp->next = masterStack;
    temp->number = var;
    masterStack = temp;
}

void deleteItem( ){
    struct stack* temp ;
    if( masterStack == NULL)
        temp = NULL;
    else
        temp = masterStack->next;
    free( masterStack);
    masterStack = temp;
}

void printStack ( ){
    struct stack* list = masterStack;
    printf("||==========\n");
    printf("||  Top   ||\n");
    printf("|| ------\n");
    while( list != NULL){
        printf("|| number: %lf\n", list->number);
        list = list->next;
    }
    printf("|| ------\n");
    printf("|| Bottom ||\n");
    printf("||==========\n");
}

void printHelp( ){
    printf("//////////////////////////////////////\n");
    printf("// UPN-Rechner  von Manuel Bellersen\n");
    printf("// ---------------------------------\n");
    printf("// Befehle:\n");
    printf("//   'end' 'e': beendet den UPN-Rechner\n");
    printf("//   'print' 'p' : zeigt Kellerinhalt an\n");
    printf("//   'del'   'd' : loescht oberstes Kellerelement\n");
    printf("//   'clear' 'c' : loescht alle Kellerelemente\n");
    printf("//   'help' 'h' '?' : Ausgabe der Hilfe\n");
    printf("// ---------------------------------\n");
    printf("// gueltige zweistellige Operationssymbole:\n");
    printf("//  '+' : Addition\n");
    printf("//  '-' : Subtraktion\n");
    printf("//  '*' : Multiplikation\n");
    printf("//  '/' : Division\n");
    printf("// ---------------------------------\n");
    printf("// gueltige einstellige Operationssymbole:\n");
    printf("//  'abs'  : Absolut\n");
    printf("//  'neg'  : Negation\n");
    printf("//  'inv'  : Invers\n");
    printf("//  'sqr'  : Quadrierung\n");
    printf("//  'sqrt' : Quadratwurzel\n");
    printf("//////////////////////////////////////\n");
}

const signed char isValidSingleOperation( const char* string){
    if( masterStack == NULL){
        printf("Fehler: ungenuegend Operanden vorhanden\n");
        return 0;
    }
    return 1;
}

const signed char isValidDoubleOperation( const char* string){
    if( masterStack == NULL){
        printf("Fehler: ungenuegend Operanden vorhanden\n");
        return 0;
    }
    if( masterStack->next == NULL){
        printf("Fehler: ungenuegend Operanden vorhanden\n");
        return 0;
    }
    return 1;
}

void addition( ){
    masterStack->next->number = masterStack->number + masterStack->next->number;
    deleteItem();
}

void subtraction( ){
    masterStack->next->number = masterStack->number - masterStack->next->number;
    deleteItem();
}

void multiplication( ){
    masterStack->next->number = masterStack->number * masterStack->next->number;
    deleteItem();
}

void division( ){
    masterStack->next->number = masterStack->number / masterStack->next->number;
    deleteItem();
}

void absolute( ){
    if( masterStack->number < 0)
        masterStack->number *= -1.0;
}

void negative( ){ masterStack->number *= -1.0; }

void inverse( ){ masterStack->number = 1.0 / masterStack->number; }

void square( ){ masterStack->number *= masterStack->number; }

void squareroot( ){ masterStack->number = sqrt(masterStack->number); }

void Input( ){
    unsigned short int i = 0;
    char inputString[ length];
    char numbers[] = "0123456789";
    char* numberString;

    for( i = 0; i < length; inputString[ i++] = '\0');
    printf("> ");
    scanf("%s", inputString);
    while( strcmp( inputString, "end") != 0 && strcmp( inputString, "e") != 0){
        numberString = strpbrk( inputString, numbers);
        if( numberString == NULL){
            if( strcmp( inputString, "abs") == 0)
                if( isValidSingleOperation( inputString)) absolute( );
            if( strcmp( inputString, "neg") == 0)
                if( isValidSingleOperation( inputString)) negative( );
            if( strcmp( inputString, "inv") == 0)
                if( isValidSingleOperation( inputString)) inverse( );
            if( strcmp( inputString, "sqr") == 0)
                if( isValidSingleOperation( inputString)) square( );
            if( strcmp( inputString, "sqrt") == 0){
                if( masterStack->number >= 0){
                    if( isValidSingleOperation( inputString)) squareroot( );
                }else
                    printf("Quadratwurzel aus negativer Zahl nicht zulaessig\n");
            }
            if( strcmp( inputString, "+") == 0)
                if( isValidDoubleOperation( inputString)) addition( );
            if( strcmp( inputString, "-") == 0)
                if( isValidDoubleOperation( inputString)) subtraction( );
            if( strcmp( inputString, "*") == 0)
                if( isValidDoubleOperation( inputString)) multiplication( );
            if( strcmp( inputString, "/") == 0){
                if( masterStack->next->number < 0 || masterStack->next->number > 0 ){
                    if( isValidDoubleOperation( inputString)) division( );
                }else
                    printf("Division durch 0 nicht erlaubt\n");
            }
            if( strcmp( inputString, "print") == 0 || strcmp( inputString, "p") == 0)
                printStack();
            if( strcmp( inputString, "del") == 0 || strcmp( inputString, "d") == 0)
                deleteItem();
            if( strcmp( inputString, "clear") == 0 || strcmp( inputString, "c") == 0){
                while( masterStack != NULL)
                        deleteItem();
            }
            if( strcmp( inputString, "help") == 0 || strcmp( inputString, "h") == 0 ||  strcmp( inputString, "?") == 0 )
                printHelp();
        }else{
            if( strlen( numberString) == strlen( inputString))
                addItem( atof( numberString));
            if(( strlen( numberString) + 1 == strlen( inputString) ) && inputString[0] == '-' )
                addItem( -(atof( numberString)));
        }
        printf("> ");
        scanf("%s", inputString);
    }
}

int main(){
    Input( );

    while( masterStack != NULL)
        deleteItem( );

    return 0;
}
