CC=g++
CFLAGS=-c -Wall
CLIBS=-lpthread
EXE=escalonador

all:${EXE}

${EXE}: lotery.o processoDix.o
	${CC} ${CLIBS} lotery.o processoDix.o -o ${EXE}

lotery.o: lotery.cpp
	${CC} ${CFLAGS} lotery.cpp

processoDix.o: processoDix.cpp
	${CC} ${CFLAGS} processoDix.cpp

#Hash.o: Hash.cpp
#	${CC} ${CFLAGS} Hash.cpp

clean:
	rm -rf *.o ${EXE}

test:
	./${EXE}
