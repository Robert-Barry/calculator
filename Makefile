# Makefile for a calculator app.

cc = gcc
OBJECTS = build/main.o

all: build calculator 

build:
	mkdir -p build

calculator: $(OBJECTS)
	$(CC) -g -o build/calculator $(OBJECTS)

build/main.o: main.c 
	$(CC) -c -o build/main.o main.c

clean:
	rm -rf build