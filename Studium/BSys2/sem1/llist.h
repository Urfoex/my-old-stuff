#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

struct llist{
    long type;
    struct llist* next;
};

typedef struct llist llist;

llist* llist_head ;

void ll_add( llist* head, long element);
void ll_remove( llist* head, long element);
int ll_isIn( llist* head, long element);
int ll_isEmpty( llist* head);
void ll_print( llist* head);

#endif
