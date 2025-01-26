#include "polycalculator.h"
#include<sstream>

using namespace std;



void PolyCalculator::input() 
{
	list1.removeAll();
	list2.removeAll();
	string poly1;
	string poly2;
    cout<< "Enter the first polynomial expression: ";
	getline(cin,poly1);
	poly1.erase(remove_if(poly1.begin(), poly1.end(), ::isspace), poly1.end());    //removing spaces 
	cout<< "Enter the second polynomial expression: ";
	getline(cin,poly2);
	poly2.erase(remove_if(poly2.begin(), poly2.end(), ::isspace), poly2.end());
	
	if (parse(poly1,list1)==false)     //invoking parse function in a way that empties list if a wrong polynomial is entered
	{
		cout<<"polynomial 1 is invalid"<<endl;
		list1.removeAll();
		list2.removeAll();
	}
	else
	{
		if (parse(poly2,list2)==false)
		{
			cout<<"polynomial 2 is invalid"<<endl;
			list2.removeAll();
			list1.removeAll();
		}
	}
	
	
}

void PolyCalculator::display(ostream& os)    //displays both polynomials using the print function
{	
	os<<"Exp1: ";
	list1.print(os);
	os<<"Exp2: ";
	list2.print(os);
}

void PolyCalculator::add()      //adds polynomials and stores result in list3, this function does not print anything
{
	list3.removeAll();
	Node* current = list1.head;
	while (current!=NULL)
	{
		list3.insert(current->coef,current->expo);
		current = current->next;
	}

	Node* current2 = list2.head;
	while (current2 != NULL)
	{
		list3.insert(current2->coef,current2->expo);
		current2 = current2->next;
	}	
}



void PolyCalculator::sub()      //subtracts polynomials and stores result in list3, this function does not print anything
{
	list3.removeAll();
	Node* current = list1.head;
	while (current!=NULL)
	{
		list3.insert(current->coef,current->expo);
		current = current->next;
	}

	Node* current2 = list2.head;
	while (current2 != NULL)
	{
		list3.insert(-(current2->coef),current2->expo);
		current2 = current2->next;
	}
}

void PolyCalculator::mul ()    //multiplies polynomials and stores result in list3, this function does not print anything
{
	list3.removeAll();
	if (list1.count_nodes()<list2.count_nodes())     //keeping the smaller list in the outer loop so every term multiplies with each term of the other list
	{
		Node* current = list1.head;
		while (current != NULL)
		{
			Node* current2 = list2.head;
			while (current2 != NULL)
			{
				list3.insert((current->coef*current2->coef), (current->expo+current2->expo));
				current2 = current2->next;
			}
			current = current->next;
		}
	}
	else
	{
		Node* current = list2.head;
		while (current != NULL)
		{
			Node* current2 = list1.head;
			while (current2 != NULL)
			{
				list3.insert((current->coef*current2->coef), (current->expo+current2->expo));
				current2 = current2->next;
			}
			current = current->next;
		}
	}
}

void PolyCalculator:: readData(string path)      //uses fstream to input polynomials and invokes the parse function on them
{
	ifstream fin(path);
    if (fin.is_open())
		{
			int count=0;
			string tempstring = "";       //stores the first two lines in two different strings which are then parsed
			string tempstring2 = "";
			while (!fin.eof())
			{
				if (count == 0)
				{
					fin>> tempstring;
				}
				else if (count == 1)
				{
					fin>> tempstring2;
				}
				count++;
			}
			if (parse(tempstring,list1)==false)
			{
				cout<<"polynomial 1 is invalid"<<endl;
				list1.removeAll();
				list2.removeAll();
			}
			else
			{
				if (parse(tempstring2,list2)==false)
				{
					cout<<"polynomial 2 is invalid"<<endl;
					list2.removeAll();
					list1.removeAll();
				}
			}
		}
        
		else
			cout<<"error finding the file, check your path"<<endl;
	
}

void PolyCalculator:: writeData(string path)    //writes the data onto a file using fstream
{
	ofstream fout(path);
	
    if (fout.is_open())
	{
		display(fout); 
		add();
		fout << "Exp 1 + Exp 2: ";
		list3.print(fout);
		sub();
		fout << "Exp 1 - Exp 2: ";
		list3.print(fout);
		mul();
		fout << "Exp 1 * Exp 2: ";
		list3.print(fout);
	}
	else
		cout<<"error finding the file, check your path"<<endl;
}

bool PolyCalculator:: parse(string expr,LinkedList& list)  //parses the string on a term by term basis and stores in the list using sstream
{
	stringstream ssstr(expr);
	while(! ssstr.eof())   //loop keeps repeating until the end of the string 
	{
		int coefficient;
		int power;
		if (ssstr.peek()=='x')    //case 1: terms starts with x
		{
			coefficient=1;
			ssstr.get();
			if (ssstr.peek()=='^')
			{	
				ssstr.get();
				if (isdigit(ssstr.peek()))
				{
					int i;
					ssstr>>i;
					power=i;
				}	
				else
				{
					return false;
				}

			}	
			else
			{
				power=1;
			}
		}	
	
		else if(ssstr.peek()=='+' or ssstr.peek()=='-')  //case 2:term starts with + or -
		{
			string i(1,ssstr.peek());   //changes the char type to string
			ssstr.get();
			if (isdigit(ssstr.peek()))
			{   
				int w;
				ssstr>>w;
				i += to_string(w);       //adds the integer to the string previously containing the sign, this helps store the + or - sign
				coefficient = stoi(i);   //converts this string to integer 
				if (ssstr.peek()=='x')
				{
					ssstr.get();
					if (ssstr.peek()=='^')
					{
						ssstr.get();
						if (isdigit(ssstr.peek()))
						{
							int g;
							ssstr>>g;
							power=g;
						}	
						else
						{
							return false;
						}
					}
					else
					{
						power=1;
					}
				}
				else
				{
					power=0;
				}

			}	
			else if(ssstr.peek()=='x')
			{
				i += "1";     
				coefficient = stoi(i);    //converting string to int, and setting coef to 1 with the sign of coef already stored above
				ssstr.get();
				if (ssstr.peek()=='^')
				{
					ssstr.get();
					if (isdigit(ssstr.peek()))
					{
						int g;
						ssstr>>g;
						power=g;
					}	
					else
					{
						return false;
					}
				}
				else
				{
					power=1;
				}

			}
			else
			{
				return false;
			}
				
			
		}
	
		else if(isdigit(ssstr.peek()))   //case 3: term starts with an integer
		{
			int i;
			ssstr>>i;
			coefficient=i;
			if(ssstr.peek()=='x')
			{
				ssstr.get();
				if (ssstr.peek()=='^')
				{
					ssstr.get();
					if (isdigit(ssstr.peek()))
					{
						int x;
						ssstr>>x;
						power=x;
					}
					else
					{
						return false;
					}
				}
				else
				{
					power = 1;
				}
			}
			else if(ssstr.peek()=='+' or ssstr.peek()=='-' or ssstr.eof())
			{
				power=0;
			}
		}

		else  //all other cases are invalid
		{
			return false;
		}

		list.insert(coefficient,power);
	}
	return true;
}





