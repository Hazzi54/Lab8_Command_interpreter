.PHONY: clean

all: build main

main: func.o main.o
	gcc build/main.o build/func.o -o main -lpthread

main.o: src/main.c src/func.h
	gcc -c src/main.c -o build/main.o

func.o: src/func.c src/func.h
	gcc -c src/func.c -o build/func.o

build:
	mkdir build

clean:
	rm -rf build main
