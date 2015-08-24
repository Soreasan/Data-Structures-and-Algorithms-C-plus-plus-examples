/*
Kenneth Adair
www.cslearner.com
This will be a sample single linked list example for Github.

This specific commit contains the creation of the "node" struct which is what our linked list will interact with.
Additionally in the "main" it contains sample syntax that we will be using as we interact with our node struct in the Linked List class.  
*/

//Input and output stream
#include <iostream>
//Used for _getch(); (get character) so the program doesn't close right as I run it
#include <conio.h>
//I no longer have to type out std::cout << "Hello";, instead I type cout << "hello";
using namespace std;

//Data structures interact with the "node" structure which contains a piece of information or data and pointers that point to other nodes.
struct node{
public:
	int data;
	node* next;
};

int main(){

	//Created a new node similar to how we create other variables.
	node sample;

	//Updated the node's data to equal 10
	sample.data = 10;

	//Created a pointer that points to nodes. 
	node* pointer;

	//Assigned the pointer that points to the address of our sample node
	pointer = &sample;

	//Updated the node's "next" pointer to be equal to the "pointer" pointer.  
	//Right now it just points to itself but this demonstrates the syntax of interacting with the node.
	sample.next = pointer;

	cout << "This will be my singly linked list example on Github" << endl;
	_getch();
	return 0;
}