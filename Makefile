.PHONY: clean

all: build main

main: func.o main.o
	gcc -g build/func.o build/main.o -o main -lpthread
	
func.o: src/func.c src/func.h
	gcc -g -c src/func.c -o build/func.o

main.o: src/main.c src/func.h
	gcc -g -c src/main.c -o build/main.o

build:
	mkdir build

clean:
	rm -rf build main
