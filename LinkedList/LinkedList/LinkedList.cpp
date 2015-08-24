/*
Kenneth Adair
www.cslearner.com
This will be a sample single linked list example for Github.

This specific commit is the node again but this time it is implemented with a class instead of a structure.  
I find this version of the node more tedious to interact with so I will most likely be going back to the structure version of nodes.
*/

//Input and output stream
#include <iostream>
//Used for _getch(); (get character) so the program doesn't close right as I run it
#include <conio.h>
//I no longer have to type out std::cout << "Hello";, instead I type cout << "hello";
using namespace std;

//Data structures interact with the "node" structure which contains a piece of information or data and pointers that point to other nodes.
//the "template<class T>" allows this node to be any data type we'd like.  We can create linked lists of strings, integers, or any other data type we'd like now
template<class T>
class node{
//private means that only instances of the class can access its own data.
private:
	//The "T" means it can be any data type such as String, Integer, Double, or even instances of classes
	T Data;
	//This is a pointer that stores the address of the next node.
	node<T>* Next;
public:

	//constructor with no inputs.  
	node(){
		//Setting a pointer to 0 makes it null
		Next = 0; 
	}

	//constructor with inputted data
	node(T input){ 
		//This updates the data to be equal to the user's input
		Data = input; 
		//Setting a pointer to 0 makes it null
		Next = 0; 
	}

	//accessors
	//When I type "nodeName.data() = 5;" it can update the value of the node to be 5.
	//When I type "nodeName.data()" it will return the value of the node
	T& data(){
		return Data;
	}

	//When I type "nodeName.next() = &nodeName" it sets the "next" pointer to point to the "nodeName" address
	//When I type "nodeName.next()" it will return the address/pointer of the "next" node
	node<T>*& next(){
		return Next;
	}
};


int main(){
	//Creating three nodes: a, b, c.  They have values of 10, 15, and 20 respectively
	node<int> a(10), b(15), c(20);

	//This allows me to change the value of a
	a.data() = 5;

	//This sets the a node's "next" pointer to point to the "b" node
	a.next() = &b;

	//This sets the b node's "next" pointer to point to the "c" node
	b.next() = &c;

	//Going to print the contents of each of the nodes:
	cout << "Node a contains: " << a.data() << endl;
	cout << "Node b contains: " << b.data() << endl;
	cout << "Node c contains: " << c.data() << endl;

	_getch();
	return 0;
}