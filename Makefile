all: run_sort

main.o: main.cpp
	g++ -c main.cpp -o main.o

oneginfunctions.o: OneginFunctions.cpp
	g++ -c OneginFunctions.cpp -o oneginfunctions.o

sort_text: main.o oneginfunctions.o
	g++ main.o oneginfunctions.o -o sort_text

run_sort: sort_text
	.\sort_text