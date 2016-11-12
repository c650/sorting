CC = g++-5
CFLAGS = -Wall -Werror -std=c++11

SRC = main.cpp
OUT = sorting.out

build: ${SRC}
	${CC} ${CFLAGS} -o ${OUT} ${SRC}

.PHONY: clean

clean:
	rm ./*.o
