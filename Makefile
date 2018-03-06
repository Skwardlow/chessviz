CC = gcc
CFLAGS  = -Wall -Werror

.PHONY: cleall: bin/chessviz

bin/chessviz: build/main.o build/board.o bin
	$(CC) $(CFLAGS) build/main.o build/board.o -o bin/chessviz

build/main.o: src/main.c src/boardviz.h build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/board.o: src/boardviz.c src/boardviz.h build
	$(CC) $(CFLAGS) -c src/boardviz.c -o build/board.o

build:
	mkdir build

bin:
	mkdir bin

clean:
rm -rf build bin
all: chessviz


chessviz: src/main.o boardviz.o
	g++ main.o boardviz.o -o hello

main.o: main.c
	g++ -c main.c

boardviz.o: boardviz.c
	g++ -c boardviz.c

