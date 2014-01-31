CC=gcc

all: sender empfanger

sender: sender.o
	gcc -Wall -o sender sender.o

sender.o: sender.c sender.h

empfanger: empfanger.o
	gcc -Wall -o empfanger empfanger.o

empfanger.o: empfanger.c empfanger.h
