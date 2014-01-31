CC=gcc

all: main child1 child2

main: main.o
	gcc -Wall -o bsys_sem8 main.o

child1: child1.o
	gcc -Wall -o child1 child1.o

child2: child2.o
	gcc -Wall -o child2 child2.o

main.o: main.c main.h

child1.o: child1.c child1.h

child2.o: child2.c child2.h
