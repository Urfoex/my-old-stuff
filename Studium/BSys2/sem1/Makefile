all: sender empfaenger 

sender: sender.o
	gcc -Wall -o sender sender.o

sender.o: sender.c structure.h

empfaenger: empfaenger.o llist.o
	gcc -Wall -o empfaenger empfaenger.o  llist.o 

empfaenger.o: empfaenger.c structure.h llist.h

llist.o: llist.c llist.h
