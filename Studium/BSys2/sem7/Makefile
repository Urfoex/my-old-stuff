CC=gcc

all: sender empfaenger 

sender: sender.o 
	gcc -Wall -lsocket -lnsl -o sender sender.o 

empfaenger: empfaenger.o 
	gcc -Wall -lsocket -lnsl -o empfaenger empfaenger.o

semaphoren.o: semaphoren.h
sender.o: sender.c semaphoren.h
empfaenger.o: empfaenger.c semaphoren.h
clean:
	rm *.o 

