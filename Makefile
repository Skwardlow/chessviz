.PHONY: clean

gCC = gcc
CFLAGS  = -Wall -Werror

all:	build bin chessviz

build:
	mkdir build

bin:
	mkdir bin

chessviz: build/main.o build/boardviz.o bin
	$(gCC) $(CFLAGS) build/main.o build/boardviz.o -o bin/chessviz

build/main.o: src/main.c src/boardviz.h build
	$(gCC) $(CFLAGS) -c src/main.c -o build/main.o

build/boardviz.o: src/boardviz.c src/boardviz.h build
	$(gCC) $(CFLAGS) -c src/boardviz.c -o build/boardviz.o

clean:
	rm -rf build bin
