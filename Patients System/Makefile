all: patients.o main.o
	gcc patients.o main.o -o main.bin -std=c99 -Wall

patients.o: 
	gcc -c patients.c -o patients.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o main.bin

run: 
	./main.bin