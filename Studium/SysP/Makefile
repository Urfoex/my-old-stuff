obj-m += esoteri.o

all: theReader theWriter
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

theReader: theReader.o
	g++ -Wall -o theReader theReader.o

theReader.o: theReader.cpp ioctl_esoteric.h
	g++ -Wall -c theReader.cpp ioctl_esoteric.h

theWriter: theWriter.o
	g++ -Wall -o theWriter theWriter.o

theWriter.o: theWriter.cpp ioctl_esoteric.h
	g++ -Wall -c theWriter.cpp ioctl_esoteric.h
