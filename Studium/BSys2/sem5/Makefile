CC=gcc

all: sender empfaenger 

sender: sender.o 
	gcc -Wall -lnsl -o sender sender.o 

empfaenger: empfaenger.o 
	gcc -Wall -lnsl -o empfaenger empfaenger.o

sender.o: sender.c
empfaenger.o: empfaenger.c
clean:
	rm -f *.o 

