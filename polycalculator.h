#ifndef POLYCACLULATOR_H
#define POLYCACLULATOR_H
#include <fstream>
#include <string>
#include "linkedlist.h"
using namespace std;

class PolyCalculator
{
private:
	LinkedList list1;
	LinkedList list2;

public:
	LinkedList list3;						   // made this public so it can be directly accessed from the main file
	void input();							   // take input the values of polynomial expressions
	void display(ostream &os = cout);		   // display both polynomials (list1 and list2)
	void add();								   // add both polynomials (list1 and list2) and save the result in list3
	void sub();								   // subtract list2 from list1 and save the results in list3
	void mul();								   // multiply both polynomials (list1 and list2) and save the result in list3
	void readData(string path);				   // read a file and load the data into the linked lists (list1 and list2)
	void writeData(string path);			   // write the polynomial expressions and the results of addition,subtraction and multiplication to a file
	bool parse(string expr, LinkedList &list); // parse a string (expr) and saves the results in a linkedlist (list). This method returns true if expression is true false otherwise
};

#endif