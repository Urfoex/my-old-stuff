#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/msg.h>

#include "structure.h"

int main( int argc, char** argv){
    int msq_ID = msgget( 46958, IPC_CREAT | 0666);
    fprintf( stderr, "ID: %d\n", msq_ID);
    struct message msg_send;
    size_t length;
    int rc;

    if( msq_ID < 0){
        perror("msq_ID");
        return -1;
    }

    msg_send.m_type = getpid();

    strcpy( msg_send.m_string, "starting...\n");
    length = strlen( msg_send.m_string) + 1;
    rc = msgsnd( msq_ID, &msg_send, length, 0);
    if( rc < 0)
        perror("msgsend");


    while( fgets( msg_send.m_string, sizeof( msg_send.m_string), stdin)){
        length = strlen( msg_send.m_string) + 1;
        rc = msgsnd( msq_ID, &msg_send, length, 0);
        if( rc < 0)
            perror("msgsend");
    }
    rc = msgsnd( msq_ID, &msg_send, 0, 0);
    printf("quitting ...\n");

    return 0;
}
