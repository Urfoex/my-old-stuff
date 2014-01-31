CC=gcc

all: sender empfaenger 

sender: sender.o 
	gcc -Wall -lsocket -lnsl -o sender sender.o 

empfaenger: empfaenger.o 
	gcc -Wall -lpthread -lrt -lsocket -lnsl -o empfaenger empfaenger.o

sender.o: sender.c
empfaenger.o: empfaenger.c
clean:
	rm *.o 

