main.o: main.c	
	gcc -c main.c -o main.o
	
math.o: math.h math.c
	gcc -c math.c -o math.o
	
all: main.o math.o
	gcc main.o math.o -o out.exe
	