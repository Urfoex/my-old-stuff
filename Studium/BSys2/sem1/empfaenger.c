#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/msg.h>

#include "structure.h"
#include "llist.h"

int main( int argc, char** argv){
    llist_head = (llist*)malloc( sizeof( llist));
    llist_head->next = NULL;
    llist_head->type = -1;


    int msq_ID = msgget( 46958, IPC_CREAT | 0666);
    fprintf( stderr, "ID: %d\n", msq_ID);
    struct message msg_receive;
    size_t length;
    int currentSender = 0;

    if( msq_ID < 0){
        perror("msq_ID");
        return -1;
    }

    do{
        length = msgrcv( msq_ID, &msg_receive, sizeof( msg_receive.m_string), 0, 0);
        if( ll_isIn( llist_head, msg_receive.m_type)){
            if( length == 0){
                ll_remove( llist_head, msg_receive.m_type);
                --currentSender;
            }
        }else{                  
            if( length != 0){
                ll_add( llist_head, msg_receive.m_type);
                ++currentSender;
            }
        }

        if( length != 0){
            printf("%d\n", currentSender);
            printf("%d\n", msg_receive.m_type);
            printf("%s", msg_receive.m_string);                                                                                    

            char filename[100];
            sprintf( filename, "%ld", msg_receive.m_type);
            FILE* file = fopen( filename, "a+");
            if( file == NULL){
                perror("fopen");
            }else{
                fwrite( msg_receive.m_string, strlen( msg_receive.m_string) + 1, 1, file);
                fclose( file);
            }
        }

    }while( !ll_isEmpty( llist_head));

    ll_print( llist_head);
    
    printf("quitting...\n");

    msgctl( msq_ID, IPC_RMID, 0);

    free(llist_head);

    return 0;
}
