/*
Kenneth Adair
www.cslearner.com
This will be a sample single linked list example for Github.

In this specific commit I have worked on the linked list some more and have completed two methods that
let me add nodes to the front or back of the linked list.  Additionally I have set up the enumerate function
to allow me to display every node in the list.  The constructor and destructor both work as well.  
HOWEVER I still don't have delete methods and I can't insert the nodes into specific spots.  
My goal is to work on these next.
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
/*
Syntax for interacting with the node:
node<int> sample;		//Created a new node named "sample"
sample.data = 10;		//Updated sample's data to be 10.
sample.next = &sample;	//Updated sample's next pointer to point at the address of the sample node
cout << "Sample node's value is: " << sample.data << endl;	//outputs the sample node's value to the console

If you use a node<T> pointer then it goes like this instead:
node<T> *myNode = new node<T>();	//Creates a new empty node
myNode->data = value;	//updates the data value
myNode->next = myNode;	//Sets the pointer equal to a pointer
myNode->next = &nodeVariableName;	//Sets the pointer equal to the address of this node.
*/

template<typename T>
class linkedList{
public:
	linkedList();	//constructor
	~linkedList();	//destructor
	void addFront(const T& value);	//Adds a node to the front of the linked list
	void addEnd(const T& value);	//Adds a node to the end of the linked list
	void remove(int position);
	void find(T value);	//Checks the linked list to see if it contains a specific value
	void enumerate();	//outputs all the contents of the linked list
private:
	node<T>* front;	//this pointer points to the node at the front
	node<T>* end;	//this pointer points to the last node
	int count;		//This tracks how many nodes are in our linked list	
};

template<typename T>
linkedList<T>::linkedList(){
	//To set a pointer to null you can either make it = 0 or make it = NULL
	front = 0;
	end = 0;
	count = 0;
}

template<typename T>
linkedList<T>::~linkedList(){
	
	node<T>* temp;
	while (front != 0){
		temp = front;
		front = front->next;
		delete temp;
	}
	end = 0;
	count = 0;
}

template<typename T>
void linkedList<T>::addFront(const T& value){

	//Create the new node with the data being equal to the inputted value and the pointer points to the previous front value
	node<T> *myNode = new node<T>();
	myNode->data = value;
	myNode->next = front;
	front = myNode;
	//Update the linked list so it knows we have an additional node
	count++;
	 
	//if this is the first node in the entire linked list we also have to update the end pointer
	if (count == 1){
		end = front;
	}
}

template<typename T>
void linkedList<T>::addEnd(const T& value){
	//Create the new node with the data being equal to the inputted value
	node<T> *myNode = new node<T>();
	myNode->data = value;
	//We don't need to update myNode->next because it will be null since it's at the end
	//Update the linked list so it knows we have an additional node
	count++;

	//If this is the only node in the list update the front pointer to point to it
	if (count == 1){
		front = myNode;
	}
	else{
		//If there is more than one node then update the previous last node to point to the new last node
		end->next = myNode;
	}
	//Update the end pointer to point to the new end node
	end = myNode;
}

template<typename T>
void linkedList<T>::enumerate(){
		node<T>* temp;
		temp = front;
		for (int i = 0; i < count; i++){
			cout << "Node " << i << ": " << temp->data << endl;
			temp = temp->next;
		}
}

int main(){
	//constructor creates a new linkedList named "myLinkedList"
	linkedList<int> myLinkedList;

	//adding 15 to the front
	myLinkedList.addFront(15);
	//adding 17 to the front, the list is now: 17->15
	myLinkedList.addFront(17);
	//Adding 19 to the front, the list is now: 19->17->15
	myLinkedList.addFront(19);
	//adding 5 to the end, the list is now 19->17->15->5
	myLinkedList.addEnd(5);
	//enumerate displays all the contents of our linked list
	myLinkedList.enumerate();

	//destructor frees up the memory that was used by our nodes in the linked list
	myLinkedList.~linkedList();
	_getch();
	return 0;
}