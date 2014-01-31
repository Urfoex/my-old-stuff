#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/sem.h>
#include "semaphoren.h"


int main( int argc, char** argv){
    int shmid ,
        shmflag = /*  IPC_CREAT  | */  0666,
        shmsize = 100,
        opflag;
    key_t shmkey = 46958;
    char* shmadr;
    char buf[100];

    /*
     * SM ID holen
     */
    fprintf( stderr, "SM-ID holen\n");
    shmid = shmget( shmkey, shmsize, shmflag);
    if( shmid < 0){
        perror("shmget");
        exit(-1);
    }

    /*
     * SM ADR fuer ID holen
     */
    fprintf( stderr, "SM-ADR fuer ID holen\n");
    shmadr = shmat( shmid, 0, 0);
    if( shmadr < 0){
        perror("shmat");
        exit(-2);
    }

    /* 
     * Semaphoren anlegen
     * 
     */
    fprintf( stderr, "Sem. anlegen\n");
    int semidFrei;
    int semidDaten;
    int semidAdd;
    int semidRem;
    int semidEnde;
    key_t keyFrei = 469581;
    key_t keyDaten = 469582;
    key_t keyAdd = 469583;
    key_t keyRem = 469584;
    key_t keyEnde = 469585;
    union semun semvalueFrei;
    union semun semvalueDaten;
    union semun semvalueAdd;
    union semun semvalueRem;
    union semun semvalueEnde;
    struct sembuf lockFrei, unlockFrei;
    struct sembuf lockDaten, unlockDaten;
    struct sembuf lockAdd, unlockAdd;
    struct sembuf lockRem, unlockRem;
    struct sembuf lockEnde, unlockEnde;

    fprintf( stderr, "Sem. holen\n");
    semidFrei = getSemaphore( keyFrei);
    semidDaten = getSemaphore( keyDaten);
    semidAdd = getSemaphore( keyAdd);
    semidRem = getSemaphore( keyRem);
    semidEnde = getSemaphore( keyEnde);

    fprintf( stderr, "lock/unlock setzen\n");
    setLock( &lockFrei);
    setLock( &lockDaten);
    setLock( &lockAdd);
    setLock( &lockRem);
    setLock( &lockEnde);
    setUnlock( &unlockFrei);
    setUnlock( &unlockDaten);
    setUnlock( &unlockAdd);
    setUnlock( &unlockRem);
    setUnlock( &unlockEnde);

    fprintf( stderr, ":: %d \n", semctl( semidFrei, 0, GETVAL, 0));
    fprintf( stderr, ":: %d \n", semctl( semidDaten, 0, GETVAL, 0));
    fprintf( stderr, ":: %d \n", semctl( semidAdd, 0, GETVAL, 0));
    fprintf( stderr, ":: %d \n", semctl( semidRem, 0, GETVAL, 0));
    fprintf( stderr, ":: %d \n", semctl( semidEnde, 0, GETVAL, 0));

    fprintf( stderr, "Ich will hier rein!\n");
    /*
     * Ende des Servers eingeleitet ?
     */
    if( semctl( semidEnde, 0, GETVAL, 0) == 0){
        fprintf( stderr, "+++ToT+++\n");
        exit( 1);
    }else{
        fprintf( stderr, "Ja, er lebt noch!\n");
    }
    
    /*
     * ich bin neu hier
     */
    if( semop( semidAdd, &lockAdd, 1) < 0){
        perror("semop: semidAdd");
        exit( -1);
    }
    sprintf( buf, "%d\n", getpid());

    /* 
     * SHM frei ?
     */
    if( semop( semidFrei, &lockFrei, 1) < 0){
        perror("semop: semidFrei");
        exit( -2);
    }
    strcpy( shmadr, buf);

    /* 
     * neue Daten!
     */
    if( semop( semidDaten, &lockDaten, 1) < 0){
        perror("semop: semidFrei");
        exit( -3);
    }

    fprintf( stderr, "Ich bin drin!\n");
    /*
     * schreibe Daten
     */
    while( fgets( buf, sizeof(buf), stdin)){
        /* 
         * SHM frei ?
         */
        fprintf( stderr, "Warte auf Freizeichen ...\n");
        if( semop( semidFrei, &lockFrei, 1) < 0){
            perror("semop: semidFrei");
            exit( -4);
        }
        fprintf( stderr, "Und schreiben.\n");
        strcpy( shmadr, buf);

        /* 
         * neue Daten!
         */
        if( semop( semidDaten, &lockDaten, 1) < 0){
            perror("semop: semidFrei");
            exit( -5);
        }
        fprintf( stderr, "Und von vorn.\n");
    }

    fprintf( stderr, "Ich will hier raus!\n");
    /*
     * ich bin weg
     */
    fprintf( stderr, "(rem)\n");
    if( semop( semidRem, &lockRem, 1) < 0){
        perror("semop: semidRem");
        exit( -6);
    }
    sprintf( buf, "%d\n", getpid());

    /* 
     * SHM frei ?
     */
    fprintf( stderr, "(frei)\n");
    if( semop( semidFrei, &lockFrei, 1) < 0){
        perror("semop: semidFrei");
        exit( -7);
    }
    strcpy( shmadr, buf);

    /* 
     * neue Daten!
     */
    fprintf( stderr, "(Daten)\n");
    if( semop( semidDaten, &lockDaten, 1) < 0){
        perror("semop: semidFrei");
        exit( -8);
    }
    fprintf( stderr, "(.Schluss.)\n");

    /*
     * SM loeschen
     */
    /*  shmdt( shmadr);
    shmctl( shmid, IPC_RMID, 0);
        */

    return 0;
}
