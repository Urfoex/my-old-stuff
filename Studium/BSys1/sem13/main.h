#ifndef _MAIN_H
#define	_MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>
    
struct satztyp;
typedef struct satztyp satztyp;

#define SIZEOF_STRING 100
#define SIZEOF_NAME 30
#define SIZEOF_VORNAME 20
#define SIZEOF_ANSCHRIFT 50
#define SIZEOF_TELEFON 20


void forgetInput( unsigned long int lenght, char* name);
void clearChar( char* array, unsigned long int size);
void clearData( satztyp* data);
char* setFilename( char* filename);

satztyp* createData();

void menu( char* filename);

void insertData( satztyp* data, char* filename, long signed int append);
void printFile( char* filename);
void printData( satztyp* data);
satztyp* readData( char* filename, unsigned long int position);
void writeData( char* filename, unsigned long int position);

void changeData( char* filename);

#ifdef	__cplusplus
}
#endif

#endif	/* _MAIN_H */

