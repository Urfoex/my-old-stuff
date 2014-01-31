#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

void ll_add( llist* head, long element){
    llist* current = head;
    while( current->next)
        current = current->next;
    current->next = (llist*)malloc( sizeof(llist));
    current->next->type = element;
}
    
void ll_remove( llist* head, long element){
    llist* current = head;
    llist* toDel = NULL;
    while( current->next){
        if( current->next->type == element){
            toDel = current->next;
            current->next = toDel->next;
            free( toDel);
            return;
        }
        current = current->next;
    }
}

int ll_isIn( llist* head, long element){
    llist* current = head;
    while( current->next){
        if( current->next->type == element)
            return 1;
        current = current->next;
    }
    return 0;
}


int ll_isEmpty( llist* head){
    if( head->next)
        return 0;
    return 1;
}

void ll_print( llist* head){
    llist* current = head;
    while( current->next){
        printf("%d\n", current->next->type);
        current = current->next;
    }
}

