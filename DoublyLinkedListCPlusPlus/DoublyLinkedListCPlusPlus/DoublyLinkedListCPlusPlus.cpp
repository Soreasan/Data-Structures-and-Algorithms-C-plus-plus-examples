/*
Kenneth ADair
www.cslearner.com

This will be sample code of a doubly linked list.  
The main difference between this and the singly linked list 
is that the nodes have a pointer that points to the previous 
node as well which makes interacting with the nodes slightly different.  
*/

#include <iostream>
#include <conio.h>
using namespace std;

template<typename T>
struct node{
	T data;
	node* next;
	node* prev;
};

template<typename T>
class doublyLinkedList{
public:
		doublyLinkedList();	//constructor 
	 	~doublyLinkedList();	//destructor 

		//Add nodes to the linked list 
		void addFront(const T& value);	//Adds a node to the front of the linked list 
	 	void addEnd(const T& value);	//Adds a node to the end of the linked list 
	 	void addAt(const int position, const T& value);	//Adds a node to a specific place in the linked list 
	 	
		//Returns the value of a specific node 
		T displayFront();
	 	T displayEnd();
	 	T displayValueAt(const int position);	//returns the value from a specific node at a specific position in the linked list 
	 	T operator[](const int position);		//this overloads the square brackets.  The method/behavior is identical to the displayValueAt method 
		
		//Deletes values 
	 	void removeFront();
	 	void removeEnd();
	 	void removeAt(int position);	//removeAt removes a node from a specific point 
	

		 //Checks linked list to see if it contains a specific value 
		 bool checkFor(T value);	//Checks the linked list to see if it contains a specific value 
	

		 //Displays all contents of the linked list 
		 void enumerateForward();	//outputs all the contents of the linked list using pointers starting in the front
		 void enumerateBackwards();	//outputs all the contents of the linked list starting at the back
	

private:
		node<T>* front;	//this pointer points to the node at the front 
		node<T>* end;	//this pointer points to the last node 
		int count;		//This tracks how many nodes are in our linked list 

};

int main(){
	cout << "This will be a doubly linked list" << endl;
	_getch();
	return 0;
}