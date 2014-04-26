CC=g++
CFLAGS=-c -Wall
CLIBS=-lpthread
EXE=escalonador

all:${EXE}

${EXE}: decker.o processoDix.o
	${CC} ${CLIBS} decker.o processoDix.o -o ${EXE}

decker.o: decker.cpp
	${CC} ${CFLAGS} decker.cpp

processoDix.o: processoDix.cpp
	${CC} ${CFLAGS} processoDix.cpp

clean:
	rm -rf *.o ${EXE}

test:
	./${EXE}
