#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG
#endif
#undef DEBUG

struct satztyp;
struct linkedList;

typedef struct satztyp satztyp;
typedef struct linkedList linkedList;


void forgetInput( unsigned long int length, char* name);
void clearChar( char* array, unsigned long int size);
void clearData( satztyp* data);
char* setFilename( char** filename);
satztyp* createData();
linkedList* insertData( satztyp* data, linkedList* lList, char* filename, short unsigned int append);
void deleteList( linkedList** lList);
void printList( linkedList* lList);

char* readList( char* filename, linkedList** lList);
char* writeList( char* filename, linkedList* lList);
char* writeFile( char* filename, linkedList* lList);

void menu( char* filename);

int main( int argc, char* argv[]){
    ( argc == 2)? menu( argv[1]) : menu( NULL);
    return 0;
}

struct satztyp{
    char name[30];
    char vorname[20];
    char anschrift[50];
    char telefon[20];
};

struct linkedList{
    linkedList* next;
    linkedList* last;
    satztyp* data;
};

static linkedList* lastItem = NULL;

void forgetInput( unsigned long int length, char* name){
    if( name == NULL) while(  fgetc( stdin) != ('\n' | '\0'));
    else
        if( ( strlen( name) == length) && ( name[ strlen( name) - 1] != '\n'))
            forgetInput( 0, NULL);
}

void clearChar( char* array, unsigned long int size){
    while( size)
        array[ --size] = '\0';
}

void clearData( satztyp* data){
    clearChar( data->anschrift, 50);
    clearChar( data->name, 30);
    clearChar( data->telefon, 20);
    clearChar( data->vorname, 20);
}

char* setFilename( char** filename){
    if( *filename == NULL ){
        printf( " Filename? : ");
        *filename = (char*) calloc( 100, sizeof(char));
        fgets( *filename, 100, stdin);
        forgetInput( 100, *filename);
        (*filename)[ strlen( *filename) - 1] = '\0';
    }
    FILE* file = NULL;
    signed short int NEU = 0;
    while( ( file = fopen( *filename, "r")) == NULL && !NEU){
        printf( ":(a)nlegen, (n)ame aendern: ");
        switch( fgetc( stdin)){
        case 'a':   forgetInput( 0, NULL);
                    NEU = 1;
                    break;
        case 'n':   forgetInput( 0, NULL);
                    free( *filename);
                    printf( " Filename? :");
                    *filename = (char*) calloc( 100, sizeof(char));
                    fgets( *filename, 100, stdin);
                    forgetInput( 100, *filename);
                    (*filename)[ strlen( *filename) - 1] = '\0';
                    break;
        default:    forgetInput( 0, NULL);
                    break;
        }
    }
    if( file) fclose( file);
    return *filename;
}

satztyp* createData(){
    satztyp* data = (satztyp*) malloc( sizeof( satztyp));
    if( data == NULL) return NULL;
    clearData( data);

    printf(" Name:\t\t");
    fgets( data->name, 30, stdin);
    forgetInput( 30, data->name);
    data->name[ strlen( data->name) - 1] = '\0';

    printf(" Vorname:\t");
    fgets( data->vorname, 20, stdin);
    forgetInput( 20, data->vorname);
    data->vorname[ strlen( data->vorname) - 1] = '\0';

    printf(" Anschrift:\t");
    fgets( data->anschrift, 50, stdin);
    forgetInput( 50, data->anschrift);
    data->anschrift[ strlen( data->anschrift) - 1] = '\0';

    printf(" Telefon:\t");
    fgets( data->telefon, 20, stdin);
    forgetInput( 20, data->telefon);
    data->telefon[ strlen( data->telefon) - 1] = '\0';

    return data;
}

linkedList* insertData( satztyp* data, linkedList* lList, char* filename, short unsigned int append){
    linkedList* list = ( linkedList*) malloc( sizeof( linkedList));
    list->next = NULL;
    lastItem = list;
    list->last = lastItem;
    list->data = data;

    if( lList == NULL)
        lList = list;
    else{
        linkedList* it = lList;
        while( it->next)
            it = it->next;
        it->next = list;
    }

    if( filename != NULL || append)
        filename = writeList( filename, list);

    return lList;
}

void deleteList( linkedList** lList){
    while( *lList){
        #ifdef DEBUG
            fprintf( stderr, "D: \t%s, %s\n", (*lList)->data->name, (*lList)->data->vorname);
            fprintf( stderr, "D: \t%s, %s\n", (*lList)->data->anschrift, (*lList)->data->telefon);
        #endif
        linkedList* temp = (*lList)->next;
        free( (*lList)->data);
        free( (*lList));
        *lList = temp;
    }
}

void printList( linkedList* lList){
    linkedList* list = lList;
    while( list){
        printf( " Name: \t\t%s\n", list->data->name);
        printf( " Vorname: \t%s\n", list->data->vorname);
        printf( " Anschrift: \t%s\n", list->data->anschrift);
        printf( " Telefon: \t%s\n\n", list->data->telefon);
        list = list->next;
    }
}

void menu( char* filename){
    linkedList* list = NULL;
    short int running = 1;
    filename = readList( filename, &list);
    while( running){
        printf(":Daten (h)inzufuegen / (a)nsehen / (l)oeschen / (e)inlesen\n");
        printf(":File (s)chreiben, (f)ile entfernen, (b)eennden: ");
        switch( fgetc(stdin)){
        case 'a':   forgetInput( 0, NULL);
                    printList( list);
                    break;
        case 'b':   forgetInput( 0, NULL);
                    running = 0;
                    break;
        case 'e':   forgetInput( 0, NULL);
                    filename = readList( NULL, &list);
                    break;
        case 'f':   forgetInput( 0, NULL);
                    remove( filename);
                    filename = NULL;
                    break;
        case 'h':   forgetInput( 0, NULL);
                    list = insertData( createData( ), list, filename,1);
                    break;
        case 'l':   forgetInput( 0, NULL);
                    deleteList( &list);
                    break;
        case 's':   forgetInput( 0, NULL);
                    writeList( filename, list);
                    break;
        default:    forgetInput( 0, NULL);
                    break;
        }
    }
    deleteList( &list);
}

char* readList( char* filename, linkedList** lList){
    setFilename( &filename);
    FILE* file = NULL;
    file = fopen( filename, "rb");
    if( file == NULL){
        file = fopen( filename, "w");
        fclose( file);
        return filename;
    }
    fseek( file, 0, SEEK_SET);
    while( !feof( file)){
        satztyp* neu = ( satztyp*) malloc( sizeof( satztyp));
        clearData( neu);
        fgets( neu->name, 100, file);
        fgets( neu->vorname, 100, file);
        fgets( neu->anschrift, 100, file);
        fgets( neu->telefon, 100, file);
        neu->name[ strlen( neu->name) - 1] = '\0';
        neu->vorname[ strlen( neu->vorname) - 1] = '\0';
        neu->anschrift[ strlen( neu->anschrift) - 1] = '\0';
        neu->telefon[ strlen( neu->telefon) - 1] = '\0';
        if(  !strlen( neu->name) && !strlen( neu->vorname) && !strlen( neu->anschrift) && !strlen( neu->telefon)){
            free( neu);
            continue;
        }
        *lList = insertData( neu, *lList, NULL,0);
    }
    fclose( file);

    return filename;
}

char* writeList( char* filename, linkedList* lList){
    setFilename( &filename);
    FILE* file = NULL;

    file = fopen( filename, "ab");
    fprintf( file, "%s\n", lastItem->data->name);
    fprintf( file, "%s\n", lastItem->data->vorname);
    fprintf( file, "%s\n", lastItem->data->anschrift);
    fprintf( file, "%s\n", lastItem->data->telefon);
    fclose( file);
    return filename;
}

char* writeFile( char* filename, linkedList* lList){
    setFilename( &filename);
    FILE* file = NULL;

    file = fopen( filename, "w+b");
    fseek( file, 0, SEEK_SET);
    while( lList){
        fprintf( file, "%s\n", lList->data->name);
        fprintf( file, "%s\n", lList->data->vorname);
        fprintf( file, "%s\n", lList->data->anschrift);
        fprintf( file, "%s\n", lList->data->telefon);
        lList = lList->next;
    }
    fclose( file);
    return filename;
}


