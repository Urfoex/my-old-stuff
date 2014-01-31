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
    fprintf( stderr, "key: %d\n", key);
    int semid,
        nsems = 1, 
        semflag = IPC_CREAT | IPC_EXCL | 0777;
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
        if( errno != EEXIST){
            perror("semget");
            exit(-3);
        }
        semid = semget(key, nsems, 0777);
        if( semid < 0){
            perror("semget");
            exit(-4);
        }
    }

    return semid;
};

void initSemaphore( int semid, union semun* semvalue){
    /*
     * Semaphore initialisieren
     */
    semvalue->val = 1;
    fprintf( stderr, "semid: %d\n", semid);
    fprintf( stderr, "semid: %d\n", semvalue->val);
    int rc = semctl( semid, 0, SETVAL, *semvalue);
    if( rc < 0){
        perror("semctl");
        exit(-4);
    }

}

void setLock( struct sembuf* lock){
    lock->sem_num = 0;
    lock->sem_op = -1;
    lock->sem_flg = SEM_UNDO;
}

void setUnlock( struct sembuf* unlock){
    unlock->sem_num = 0;
    unlock->sem_op = 1;
    unlock->sem_flg = SEM_UNDO;
}

void clearBuf( char* buf, int n){
    fprintf( stderr, "Sauber machen ...");
    char b[n];
    while(n){
        b[n-1] = '\0';
        --n;
    }
    strcpy( buf, b);
    fprintf( stderr, "...fertsch.\n");
}
