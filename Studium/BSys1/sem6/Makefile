CC=gcc

all: sem6 prim

main.o: main.c main.h

prim0.o: prim0.c prim0.h

prim_child.o: prim_child.c prim_child.h

sem6: main.o
	gcc -lm -Wall -o sem6 main.o

prim: prim0.o prim_child.o
	gcc -lm -Wall -o prim prim0.o prim_child.o
