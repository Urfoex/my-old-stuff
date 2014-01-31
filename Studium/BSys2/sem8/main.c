#include "main.h"

struct satztyp {
    char name[SIZEOF_NAME];
    char vorname[SIZEOF_VORNAME];
    char anschrift[SIZEOF_ANSCHRIFT];
    char telefon[SIZEOF_TELEFON];
};

int main( int argc, char** argv ) {
    if( argc < 2)
        menu( NULL);
    else
        menu( argv[1]);

    return (EXIT_SUCCESS );
}


void forgetInput( unsigned long int lenght, char* name){
    if( name == NULL)
        while(  fgetc( stdin) != ('\n' | '\0'));
    else
        if( ( strlen( name) == lenght) && ( name[ strlen( name) - 1] != '\n'))
            forgetInput( 0, NULL);
}

void clearChar( char* array, unsigned long int size){
    if( !array){
        fprintf( stderr, "no array\n");
        return;
    }
    while( size)
        array[ --size] = '\0';
}

void clearData( satztyp* data){
    clearChar( data->anschrift, SIZEOF_ANSCHRIFT);
    clearChar( data->name, SIZEOF_NAME);
    clearChar( data->telefon, SIZEOF_TELEFON);
    clearChar( data->vorname, SIZEOF_VORNAME);
}

char* setFilename( char* filename){
    if( filename == NULL ){
        printf( " Filename? : ");
        filename = (char*) calloc( SIZEOF_STRING, sizeof(char));
        fgets( filename, SIZEOF_STRING, stdin);
        forgetInput( SIZEOF_STRING, filename);
        (filename)[ strlen( filename) - 1] = '\0';
    }
    FILE* file = NULL;
    signed short int NEU = 0;
    while( ( file = fopen( filename, "r")) == NULL && !NEU){
        printf( ":(a)nlegen, (n)ame aendern: ");
        switch( fgetc( stdin)){
        case 'a':   forgetInput( 0, NULL);
                    NEU = 1;
                    break;
        case 'n':   forgetInput( 0, NULL);
                    free( filename);
                    printf( " Filename? :");
                    filename = (char*) calloc( SIZEOF_STRING, sizeof(char));
                    fgets( filename, SIZEOF_STRING, stdin);
                    forgetInput( SIZEOF_STRING, filename);
                    (filename)[ strlen( filename) - 1] = '\0';
                    break;
        default:    forgetInput( 0, NULL);
                    break;
        }
    }
    if( file) fclose( file);
    return filename;
}

satztyp* createData(){
    satztyp* data = (satztyp*) malloc( sizeof( satztyp));
    if( data == NULL)
        return NULL;
    clearData( data);

    printf(" Name:\t\t");
    fgets( data->name, SIZEOF_NAME, stdin);
    forgetInput( SIZEOF_NAME, data->name);
    data->name[ strlen( data->name) - 1] = '\0';

    printf(" Vorname:\t");
    fgets( data->vorname, SIZEOF_VORNAME, stdin);
    forgetInput( SIZEOF_VORNAME, data->vorname);
    data->vorname[ strlen( data->vorname) - 1] = '\0';

    printf(" Anschrift:\t");
    fgets( data->anschrift, SIZEOF_ANSCHRIFT, stdin);
    forgetInput( SIZEOF_ANSCHRIFT, data->anschrift);
    data->anschrift[ strlen( data->anschrift) - 1] = '\0';

    printf(" Telefon:\t");
    fgets( data->telefon, SIZEOF_TELEFON, stdin);
    forgetInput( SIZEOF_TELEFON, data->telefon);
    data->telefon[ strlen( data->telefon) - 1] = '\0';

    return data;
}

void insertData( satztyp* data, char* filename, long signed int append){
    if( !filename){
        fprintf( stderr, "no filename\n");
        return;
    }

    FILE* fp = fopen( filename, "r+b");
    if( !fp){
        if( stat( filename, NULL)){
            assert( errno == ENOENT);
            fp = fopen( filename, "wb");
        }
    }

    flock lock;
    int rc = 0;

    if( append < 0){
        /* ********************************************************************* */
        /* *
         * Setzten des Write-Lock
         * */
        lock.l_type     = F_WRLCK;
        lock.l_whence   = SEEK_END;
        lock.l_start    = 0;
        lock.l_len      = sizeof( satztyp);
        rc = fcntl( fileno( fp), F_SETLKW, &lock);
        if( rc < 0){
            perror("fcntl");
            fclose( fp);
            return;
        }
        fprintf( stderr, "( new-write-lock )\n");
        /* ********************************************************************* */

        fseek( fp, 0, SEEK_END);
    }else{
        /* ********************************************************************* */
        /* *
         * Setzten des Write-Lock
         * */
        lock.l_type     = F_WRLCK;
        lock.l_whence   = SEEK_SET;
        lock.l_start    = append * sizeof( satztyp);
        lock.l_len      = sizeof( satztyp);
        rc = fcntl( fileno( fp), F_SETLKW, &lock);
        if( rc < 0){
            perror("fcntl");
            fclose( fp);
            return;
        }
        fprintf( stderr, "( old-write-lock )\n");
        /* ********************************************************************* */

        fseek( fp, append * sizeof(satztyp), SEEK_SET);
    }
    fwrite( data, sizeof( satztyp), 1, fp);
    /* ************************************************************************* */
    /* *
     * Freigabe des Read-Lock
     * */
    lock.l_type = F_UNLCK;
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( n/o-write-unlock )\n");

    fclose( fp);
}

void printFile( char* filename){
    satztyp data;
    unsigned long int i = 0;
    if( !filename){
        fprintf( stderr, "no filename\n");
        return;
    }
    FILE* fp = fopen( filename, "rb");
    if( !fp){
        perror("fopen");
        return;
    }

    /* *
     * Setzten des ersten Read-Lock
     * */
    flock lock;
    unsigned long int pos = 0;
    int rc = 0;
    lock.l_type     = F_RDLCK;
    lock.l_whence   = SEEK_SET;
    lock.l_start    = pos;
    lock.l_len      = sizeof( satztyp);
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( lock )\n");

    fseek( fp, 0, SEEK_SET);
    while( fread( &data, sizeof( satztyp), 1, fp)){
        /* *
         * Freigabe des Read-Lock
         * */
        lock.l_type = F_UNLCK;
        rc = fcntl( fileno( fp), F_SETLKW, &lock);
        if( rc < 0){
            perror("fcntl");
            fclose( fp);
            return;
        }
        fprintf( stderr, "( unlock )\n");

        printf( " Datensatz: \t%d\n", i++);
        printData( &data);
        clearData( &data);

        /* *
         * Setzten des naechsten Read-Lock
         * */
        ++pos;

        lock.l_type     = F_RDLCK;              
        lock.l_whence   = SEEK_SET;
        lock.l_start    = pos * sizeof( satztyp);
        lock.l_len      = sizeof( satztyp);
        rc = fcntl( fileno( fp), F_SETLKW, &lock);
        if( rc < 0){
            perror("fcntl");
            fclose( fp);
            return;
        }
        fprintf( stderr, "( lock )\n");

        fseek( fp, pos * sizeof( satztyp), SEEK_SET);
    }
    /* *
     * Freigabe des letzten Read-Lock
     * */
    lock.l_type = F_UNLCK;
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( unlock )\n");

    fclose( fp);
}

void printData(satztyp* data){
    if( !data){
        fprintf( stderr, "no data\n");
        return;
    }
    printf( " Name: \t\t%s\n", data->name);
    printf( " Vorname: \t%s\n", data->vorname);
    printf( " Anschrift: \t%s\n", data->anschrift);
    printf( " Telefon: \t%s\n\n", data->telefon);
}

void printOneSet( char* filename){
    printf("Position: ");
    unsigned long int pos = 0;
    scanf( "%lu", &pos);
    forgetInput( 0, NULL);
    readData( filename, pos);
}

void changeOneSet( char* filename){
    unsigned long int position = 0;
    satztyp* data = NULL;
    satztyp* neuData = NULL;
    printf("Position: ");
    scanf( "%lu", &position);
    forgetInput( 0, NULL);
    /* ********************************************************************* */
    /* *
     * aus readData()
     * */
    data = (satztyp*) malloc( sizeof( satztyp));
    if( !filename){
        fprintf( stderr, "no filename\n");
        return;
    }
    FILE* fp = fopen( filename, "r+b");
    if( !fp){
        perror("fopen");
        return;
    }

    /* *
     * Setzten des Write-Lock
     * */
    flock lock;
    int rc = 0;
    lock.l_type     = F_WRLCK;
    lock.l_whence   = SEEK_SET;
    lock.l_start    = position * sizeof( satztyp);
    lock.l_len      = sizeof( satztyp);
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( write-lock )\n");
    
    if( fseek( fp, position * sizeof( satztyp), SEEK_SET)){
        perror("fseek");
        fclose( fp);
        return;
    }
    fread( data, sizeof( satztyp), 1, fp);

    printf( " Datensatz: \t%d\n", position);
    printData( data);
    /* ********************************************************************* */

    printf("Richtig ? (j/n) :");
    switch( fgetc(stdin)){
    case 'j':
        forgetInput( 0, NULL);

        neuData = createData();
        if( !strncmp( neuData->anschrift, "\0", 1))
            strcpy( neuData->anschrift, data->anschrift);
        if( !strncmp( neuData->name, "\0", 1))
            strcpy( neuData->name, data->name);
        if( !strncmp( neuData->telefon, "\0", 1))
            strcpy( neuData->telefon, data->telefon);
        if( !strncmp( neuData->vorname, "\0", 1))
            strcpy( neuData->vorname, data->vorname);

        /* ***************************************************************** */
        /* *
         * aus insertData()
         * */
        fseek( fp, position * sizeof(satztyp), SEEK_SET);
        fwrite( neuData, sizeof( satztyp), 1, fp);
        /* ***************************************************************** */

        break;
    case 'n':
        forgetInput( 0, NULL);
        printf("abort\n");
        break;
    default:
        forgetInput( 0, NULL);
        printf("assuming no ...\n");
        break;
    }

    /* ********************************************************************* */
    /* *
     * aus readData()
     * */
    
    /* *
     * Freigabe des Read-Lock
     * */
    lock.l_type = F_UNLCK;
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( write-unlock )\n");
    
    fclose( fp);
    /* ********************************************************************* */
}

void menu( char* filename){
    short int running = 1;
    satztyp* neuData;
    filename = setFilename( filename);
    while( running){
        printf(":Daten (h)inzufuegen / (a)nsehen / a(e)ndern\n");
        printf(":(d)atensatz ansehen\n");
        printf(":File (n)eu / (l)oeschen , (b)eenden: ");
        switch( fgetc(stdin)){
        case 'a':   forgetInput( 0, NULL);
                    printFile( filename);
                    break;
        case 'b':   forgetInput( 0, NULL);
                    running = 0;
                    break;
        case 'd':   forgetInput( 0, NULL);
                    printOneSet( filename);
                    break;
        case 'e':   forgetInput( 0, NULL);
                    changeOneSet( filename);
                    break;
        case 'h':   forgetInput( 0, NULL);
                    neuData = createData();
                    insertData( neuData, filename, -1);
                    free( neuData);
                    break;
        case 'l':   forgetInput( 0, NULL);
                    remove( filename);
                    filename = NULL;
                    break;
        case 'n':   forgetInput( 0, NULL);
                    filename = setFilename( NULL);
                    break;
        default:    forgetInput( 0, NULL);
                    break;
        }
    }
}

satztyp* readData( char* filename, unsigned long int position){
    satztyp* data = (satztyp*) malloc( sizeof( satztyp));
    if( !filename){
        fprintf( stderr, "no filename\n");
        return;
    }
    FILE* fp = fopen( filename, "rb");
    if( !fp){
        perror("fopen");
        return NULL;
    }

    /* *
     * Setzten des Read-Lock
     * */
    flock lock;
    int rc = 0;
    lock.l_type     = F_RDLCK;
    lock.l_whence   = SEEK_SET;
    lock.l_start    = position * sizeof( satztyp);
    lock.l_len      = sizeof( satztyp);
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( read-lock )\n");
    
    if( fseek( fp, position * sizeof( satztyp), SEEK_SET)){
        perror("fseek");
        return NULL;
    }
    fread( data, sizeof( satztyp), 1, fp);

    /* *
     * Freigabe des Read-Lock
     * */
    lock.l_type = F_UNLCK;
    rc = fcntl( fileno( fp), F_SETLKW, &lock);
    if( rc < 0){
        perror("fcntl");
        fclose( fp);
        return;
    }
    fprintf( stderr, "( read-unlock )\n");
    
    fclose( fp);
    printf( " Datensatz: \t%d\n", position);
    printData( data);
    
    return data;
}
