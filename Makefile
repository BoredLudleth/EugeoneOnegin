all: run_sort

main.o: main.cpp
	g++ -c main.cpp -o main.o

oneginfunctions.o: OneginFunctions.cpp
	g++ -c OneginFunctions.cpp -o oneginfunctions.o

run_sort: main.o oneginfunctions.o
	g++ main.o oneginfunctions.o -o run_sort

clean:
	rm *.o *.exe
