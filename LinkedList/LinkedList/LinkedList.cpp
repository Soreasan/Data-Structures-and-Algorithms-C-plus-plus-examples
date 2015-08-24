/*
Kenneth Adair
www.cslearner.com
This will be a sample single linked list example for Github.

This specific commit is the node again but this time it is implemented with a template structure that can be any data type.  
The class version of the node was too tedious to use and the previous struct version of the node only worked with ints
so I settled on this version of the node that takes advantage of the template which allows me to have any data type I'd like
and the simplicity of the structure which should make creating the rest of the linked list much easier.  
*/

//Input and output stream
#include <iostream>
//Used for _getch(); (get character) so the program doesn't close right as I run it
#include <conio.h>
//I no longer have to type out std::cout << "Hello";, instead I type cout << "hello";
using namespace std;

//Data structures interact with the "node" structure which contains a piece of information or data and pointers that point to other nodes.
//the "template<class T>" allows this node to be any data type we'd like.  We can create linked lists of strings, integers, or any other data type we'd like now
template<typename T>
struct node{
	T data;
	node* next;
};


int main(){
	//Sample syntax for interacting with the node
	node<int> sample;
	sample.data = 10;
	sample.next = &sample;
	cout << "Sample node's value is: " << sample.data << endl;

	//Manually created linked list:
	node<int> a, b, c;
	a.data = 1;
	b.data = 2;
	c.data = 3;
	a.next = &b;
	b.next = &c;
	//The linked list looks like this:
	// a->b->c

	_getch();
	return 0;
}