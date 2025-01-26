#include "linkedlist.h"


LinkedList::LinkedList ()   //constructor
{
	this->head = NULL;  
}


void LinkedList:: insert(int coef, int expo)   //inserting a node into the linked list 
{
    if (count_nodes()==0)      //if the linked list is empty just adds a node and returns from the funtion 
    {
        Node* v = new Node(coef, expo);
        head = v; 
        return;
    }
   
    Node* current = head;
    Node* previous_node = NULL;
   
    while (current!= NULL)   //iterates over the linked list 
    {
        if (expo > current->expo)    //if expo is greater than the expo of the current node this happens
        {
            Node* temp = current;
            Node* v = new Node(coef, expo);
            current = v;
            current->next = temp;
            if (previous_node != NULL)    //inserts the node in the middle of the linked list by using the previous node pointer created
            {
                previous_node->next = current;
            }
            else
            {
                head = current;
            }
            return;

        }
        else if (current->expo == expo)    //if expo is equal to the expo of the current node this happens
        {
            current->coef = current->coef + coef;
            return;
        }
        else if (current->expo > expo)     //if expo is less than the expo of the current node this happens
        {
            if (current->next == NULL)   //this is the case if the list finishes at current node, a node is inserted after that and we return from function 
            {
                Node* v = new Node(coef, expo);
                current->next = v; 
                return;
            }
            else     //this is teh case if list is not finishing at current node, we just update the  previous node and current pointers and move forward in the whiel loop
            {
                previous_node = current;
                current = current->next;

            }
        }
    }
}


void LinkedList:: removeAll()   //removes all nodes by iterating over linked list 
{
	while (head!=NULL){
		Node* old = head; 
		head = old->next;
		delete old; 
	}
}

int LinkedList :: count_nodes()   //counts the nodes in a linked list 
{
    Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList:: print(ostream& os) const  //prints the linked list with taking into account the sign of the coef of different nodes
{
    Node* current = head; 
	while (current != NULL)
    {
        if (current->coef >= 0)
        {
            os<<"+"<<current->coef<<"x"<<"^"<<current->expo;
        }
        else
        {
            os<<current->coef<<"x"<<"^"<<current->expo;
        }
        current = current->next;
    }
    os<<endl;
}

LinkedList::~LinkedList ()      //decontructor 
{
	removeAll();
}




