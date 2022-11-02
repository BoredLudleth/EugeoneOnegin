CC=g++
CFLAGS=-c -Wall	

all: run_sort

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

oneginfunctions.o: OneginFunctions.cpp
	$(CC) $(CFLAGS) OneginFunctions.cpp -o oneginfunctions.o

run_sort: main.o oneginfunctions.o
	$(CC) main.o oneginfunctions.o -o run_sort

clean:
	rm *.o
