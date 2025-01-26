
output.out: linkedlist.o main.o polycalculator.o
	g++ linkedlist.o main.o polycalculator.o -o output.out

main.o: main.cpp
	g++ -c main.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c linkedlist.cpp
polycalculator.o: polycalculator.cpp polycalculator.h
	g++ -c polycalculator.cpp
clean:
	rm *.o *.out
