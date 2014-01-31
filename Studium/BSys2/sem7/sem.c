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

union semun{
    int val;
    struct semid_ds* buf;
    ushort_t* array;
};

int getSemaphore( key_t key){
    /* 
     * Semaphoren anlegen
     * */
    int semid,
        nsems = 1, 
        semflag = IPC_CREAT | IPC_EXCL | 0666;
    union semun{
        int val;
        struct semid_ds* buf;
        ushort_t* array;
    } semvalue;
    semvalue.val = 1;

    /*
     * Semaphore anlegen
     */
    semid = semget( key, nsems, semflag);    
    if( semid < 0){
        perror("semget");
        exit(-3);
    }

    return semid;
};

void initSemaphore( int semid, semun* semvalue){
    /*
     * Semaphore initialisieren
     */
    rc = semctl( semid, 0, SETVAL, *semvalue);
    if( rc < 0){
        perror("semctl");
        exit(-4);
    }

}
