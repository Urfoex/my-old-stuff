#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Item{
	unsigned short int number;
};

struct vlist{
	struct vlist* next;
	struct vlist* previous;
	struct Item* item;
};


void addItem( struct Item* item, struct vlist* list);
struct vlist* newList( );
void deleteList( struct vlist* list);
unsigned short int generateNumber();
struct Item* createItem();
void printList( struct vlist* list);
void fillList( struct vlist* list);

struct Item* createItem(){
	struct  Item* item = ( struct Item*) malloc( sizeof( struct Item));
	item->number = generateNumber();
	return item;
}

unsigned short int generateNumber(){
	return ( rand() % 10);
}

struct vlist* newList(){
	struct vlist* list = ( struct vlist*) malloc( sizeof( struct vlist));
	list->next = NULL;
	list->previous = NULL;
	list->item = NULL;
	return list;
}

void deleteList( struct vlist* list){
	struct vlist* temp = list;
	while( temp->next)
		temp = temp->next;
	printf("Deleting:  ");
	if( temp->previous){
        while( temp != list){
            printf(" %i ", temp->item->number);
            temp = temp->previous;
            free( temp->next->item);
            temp->next->item = NULL;
            free( temp->next);
            temp->next = NULL;
        }
	}
	printf(" %i ", list->item->number);
	free( list->item);
	list->item = NULL;
	free( list);
	list = NULL;
	printf("\nClear\n");
}

void printList( struct vlist* list){
	struct vlist* temp = list;
	printf("Numbers:   ");
	printf(" %i ", temp->item->number);
	while( temp->next){
		temp = temp->next;
		printf(" %i ", temp->item->number);
	}
	printf("\n");
}

void addItem( struct Item* item, struct vlist* list){
	struct vlist* temp = list;
	while( temp->next)
		temp = temp->next;
	temp->next = newList();
	temp->next->previous = temp;
	temp->next->next = NULL;
	temp->next->item = item;
}

void fillList( struct vlist* list){
	struct Item* item = createItem();
	while( item->number != 0){
		addItem( item, list);
		item = createItem();
	}
	free( item);
}


int main( int argc, char* argv[]){
	srand( time( NULL));
	struct vlist* MasterList = newList();
	MasterList->item = createItem();
	while( !MasterList->item->number) MasterList->item->number = generateNumber();
	fillList( MasterList);
	printList( MasterList);
	deleteList( MasterList);

	return 0;
}
