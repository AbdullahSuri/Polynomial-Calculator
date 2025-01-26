#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include <iomanip>

#include "linkedlist.h"
#include "polycalculator.h"
using namespace std;

void listCommands()
{
	cout << "List of available Commands:" << endl
		 << "display              : Display the Polynomials (Linked Lists)" << endl
		 << "input                : Input Polynomial expressions from keyboard" << endl
		 << "add                  : Add the Polynomials (Linked Lists)" << endl
		 << "sub                  : Subtract the Polynomials (Linked Lists)" << endl
		 << "mul                  : Multiply the polynomials (Linked Lists)" << endl
		 << "read <file_name>     : Load the data from <file> and add it into the Linked Lists" << endl
		 << "write <file_name>    : Dump the contents of the resultant Linked list to a <file>" << endl
		 << "help                 : Display the list of available commands" << endl
		 << "exit                 : Exit the Program" << endl;
}

// main function
int main()
{

	PolyCalculator polycalc;

	listCommands();
	string user_input;
	string command;
	string parameter;
	do
	{
		cout << ">";
		getline(cin, user_input);

		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr, command, ' ');
		getline(sstr, parameter);

		if (command == "display")
			polycalc.display();
		else if (command == "input")
			polycalc.input();
		else if (command == "add")
		{
			cout << "Exp1 + Exp2 = ";
			polycalc.add();
			polycalc.list3.print();
		} // for the add, sub and mul methods added cout here so it does not effect the write method
		else if (command == "sub")
		{
			cout << "Exp1 - Exp2 = ";
			polycalc.sub();
			polycalc.list3.print();
		}
		else if (command == "mul")
		{
			cout << "Exp1 * Exp2 = ";
			polycalc.mul();
			polycalc.list3.print();
		}
		else if (command == "read")
			polycalc.readData(parameter), polycalc.display();
		else if (command == "write")
			polycalc.writeData(parameter);
		else if (command == "help")
			listCommands();
		else if (command == "exit" or command == "quit")
			break;
		else if (command == "")
			continue;
		else
		{
			cout << "Invalid Command!!" << endl;
		}

	} while (true);

	return EXIT_SUCCESS;
}