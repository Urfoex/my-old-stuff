CC=gcc

all: sender empfaenger steuerinfo

sender: sender.o steuerinfo.o
	gcc -lsocket -lnsl -Wall -o sender sender.o steuerinfo.o

empfaenger: empfaenger.o steuerinfo.o
	gcc -lsocket -lnsl -Wall -o empfaenger empfaenger.o steuerinfo.o

steuerinfo: steuerinfo.o


sender.o: sender.c


empfaenger.o: empfaenger.c


steuerinfo.o: steuerinfo.c steuerinfo.h


clean:
	rm -f *.o 46958.* empfaenger sender

