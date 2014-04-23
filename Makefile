CC=gcc
CFLAGS=-c -Wall
CLIBS=-lpthread
all:macacos

macacos: macacos.o main.o
	${CC} ${CLIBS} macacos.o main.o -o macacos

macacos.o: macacos.c
	${CC} ${CFLAGS} macacos.c

main.o: main.c
	${CC} ${CFLAGS} main.c

clean:
	rm -rf *.o macacos

test:
	./macacos
