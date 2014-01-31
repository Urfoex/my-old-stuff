#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/sem.h>
#include "semaphoren.h"


int semidEnde;
struct sembuf lockEnde, unlockEnde;

int ENDE = 0;
void sigTermAction( int snr){
    fprintf( stderr, "server ending ...\n");
    if( semctl( semidEnde, 0, GETVAL, 0) != 0){
        if( semop( semidEnde, &lockEnde, 1) < 0){
            perror("semop: Ende?");
            exit(-42);
        }
    }
    ENDE = 1;
}


int main( int argc, char** argv){
    sigset( SIGINT, sigTermAction);
    int shmid ,
        shmflag = IPC_CREAT | 0666,
        shmsize = 100,
        opflag,
        changed = 0;
    key_t shmkey = 46958;
    char* shmadr;
    char buf[100];
    int clients = 0;

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
     * */
    fprintf( stderr, "Sem. anlegen\n");
    int semidFrei;
    int semidDaten;
    int semidAdd;
    int semidRem;
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

    fprintf( stderr, "Sem. holen\n");
    semidFrei = getSemaphore( keyFrei);
    semidDaten = getSemaphore( keyDaten);
    semidAdd = getSemaphore( keyAdd);
    semidRem = getSemaphore( keyRem);
    semidEnde = getSemaphore( keyEnde);

    fprintf( stderr, "Sem. initiieren\n");
    initSemaphore( semidFrei, &semvalueFrei);
    initSemaphore( semidDaten, &semvalueDaten);
    initSemaphore( semidAdd, &semvalueAdd);
    initSemaphore( semidRem, &semvalueRem);
    initSemaphore( semidEnde, &semvalueEnde);

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

    fprintf( stderr, "Jetzt gehts los!\n");

    /*
     * SHM lesen und ausgeben
     */
    while( !ENDE || clients){
        /*
         * Daten da?
         */
        if( semctl( semidDaten, 0, GETVAL, 0) == 0){
            changed = 1;
            fprintf( stderr, "Was neues?\n");
        }else{
            continue;
        }

        fprintf( stderr, "(Daten)\n");
        if( semop( semidDaten, &unlockDaten, 1) < 0){
            perror("semop: Daten da?");
            continue;
        }
        /*
         * neu hier ?
         */
        fprintf( stderr, "(neu)\n");
        if( semctl( semidAdd, 0, GETVAL, 0) == 0){
            ++clients;
            changed = 1;
            fprintf( stderr, "Oh, ein neuer!\n");
            if( semop( semidAdd, &unlockAdd, 1) < 0){
                perror("semop: Add");
            }
        }
        /*
         * raus hier?
         */
        fprintf( stderr, "(raus)\n");
        if( semctl( semidRem, 0, GETVAL, 0) == 0){
            --clients;
            changed = 1;
            fprintf( stderr, "Oh, einer weniger!\n");
            if( semop( semidRem, &unlockRem, 1) < 0){
                perror("semop: Add");
            }
        }
        if( changed == 0 && clients == 0){
            continue;
        }else{
            changed = 0;
            fprintf( stderr, "Frischfleisch!\n");
        }
        /*
         * Daten lesen
         */
        strcpy( buf, shmadr);
        /*
         * buf schreiben
         */
        fprintf( stdout, "> %s", buf);
        /*
         * SHM leeren
         */
        clearBuf( buf, 100);
        strcpy( shmadr, buf);
        /*
         * Daten freigeben
         */
//        if( semop( semidDaten, &unlockDaten, 1) < 0){
//            perror("semop: Daten freigeben");
//        }
        /*
         * SHM freigeben
         */
        if( semop( semidFrei, &unlockFrei, 1) < 0){
            perror("semop: Daten freigeben");
        }
        fprintf( stderr, "Nochmal!\n");

        /*
         * Muss wieder alles auf 1 setzten,
         * denn SEM_UNDO macht auch bei return 0
         * beim Sender alles von ihm wieder rueck-
         * gaening ...
         */
        while( semctl(semidFrei, 0, GETVAL, 0) > 1){
            semop( semidFrei, &lockFrei, 1);
        }
        while( semctl(semidDaten, 0, GETVAL, 0) > 1){
            semop( semidDaten, &lockDaten, 1);
        }
        while( semctl(semidAdd, 0, GETVAL, 0) > 1){
            semop( semidAdd, &lockAdd, 1);
        }
        while( semctl(semidRem, 0, GETVAL, 0) > 1){
            semop( semidRem, &lockRem, 1);
        }
        fprintf( stderr, ":: %d \n", semctl( semidFrei, 0, GETVAL, 0));
        fprintf( stderr, ":: %d \n", semctl( semidDaten, 0, GETVAL, 0));
        fprintf( stderr, ":: %d \n", semctl( semidAdd, 0, GETVAL, 0));
        fprintf( stderr, ":: %d \n", semctl( semidRem, 0, GETVAL, 0));
        fprintf( stderr, ":: %d \n", semctl( semidEnde, 0, GETVAL, 0));
    };

    /*
     * Semaphoren loeschen
     */
    semctl( semidFrei, 0, IPC_RMID, 0);
    semctl( semidDaten, 0, IPC_RMID, 0);
    semctl( semidAdd, 0, IPC_RMID, 0);
    semctl( semidRem, 0, IPC_RMID, 0);
    semctl( semidEnde, 0, IPC_RMID, 0);

    /*
     * SM loeschen
     */
    shmdt( shmadr);
    shmctl( shmid, IPC_RMID, 0);

    return 0;
}
