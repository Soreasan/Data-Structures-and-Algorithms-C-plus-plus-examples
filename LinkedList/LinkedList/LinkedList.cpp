/*
Kenneth Adair
www.cslearner.com

Imagine that Little Timmy has an array with 5 spots in it to store his 5 friends.  He gets a new friend one day.
Little Timmy sighs and pulls out a shotgun.  Since there are only 5 spots he has to either make a new larger array and move
every single person to the new array or he has to kill one of his existing friends to open up a spot for his new friend.  
Little Timmy is on a budget so he can't afford to make a new array.  As Little Timmy approaches his array he hears a voice from
the Data Structure Wizard: 
"What if I told you there's a better way?"
"How?"
"Instead of an array you could use a linked list to store your friends.  
Linked lists allow you to insert friends, removeAt friends, and enumerate friends freely.
You wouldn't have to use your shotgun on your old friends every time you got new friends!"
"Wow that sounds awesome!  I could really expand or shrink the linked list whenever I wanted?"
"Yup, any time you insert a new friend the linked list just magically creates more room and any
time you removeAt a friend it magically shrinks the linked list so it always takes the bare minimum 
amount of room unlike those dirty nasty arrays."
"Wow I'm in!"
Then Little Timmy bought a Linked List from his friend the Data Structure Wizard and he never viciously murdered
his friends because he ran out of room ever again.  
The end.  

This is a singly unordered linked list in C++.  A linked list is a linear list of nodes in which the order depends by the 
pointers in the individual nodes.  A linked list is similar to an array but much more versatile.  

Big O notation of linked list:
(Taken from http://bigocheatsheet.com/)
Access: O(n)
Search: O(n)
Insertion: O(1)
Deletion: O(1)
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

	//Add nodes to the linked list
	void addFront(const T& value);	//Adds a node to the front of the linked list
	void addEnd(const T& value);	//Adds a node to the end of the linked list
	void addAt(const int position, const T& value);	//Adds a node to a specific place in the linked list

	//Returns the value of a specific node
	T displayFront();
	T displayEnd();
	T displayValueAt(const int position);	//returns the value from a specific node at a specific position in the linked list
	T operator[](const int position);	//this overloads the square brackets.  The method/behavior is identical to the displayValueAt method

	//Deletes values
	void removeFront();
	void removeEnd();
	void removeAt(int position);	//removeAts a node from a specific point

	//Checks linked list to see if it contains a specific value
	bool checkFor(T value);	//Checks the linked list to see if it contains a specific value

	//Displays all contents of the linked list
	void enumerate();	//outputs all the contents of the linked list using pointers

private:
	node<T>* front;	//this pointer points to the node at the front
	node<T>* end;	//this pointer points to the last node
	int count;		//This tracks how many nodes are in our linked list	
};

//constructor
template<typename T>
linkedList<T>::linkedList(){
	//To set a pointer to null you can either make it = 0 or make it = NULL
	front = 0;
	end = 0;
	count = 0;
}

//destructor
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

//A method that adds a node to the front of the linked list
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

//A method that adds a node to the end of the linked list
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
void linkedList<T>::addAt(const int position, const T& value){
	//If the index is negative or too big throw an error
	if (position < 0 || position > count){
		return;
	}//If the position is the front node just call addFront 
	else if (position == 0){
		addFront(value);
	}//If the position is the end node just call addEnd
	else if (position == count){
		addEnd(value);
	}//Otherwise here is the default case of inserting the node somewhere in the middle
	else{
		//This pointer tracks which node we're currently on
		node<T>* currentNode = front;
		//This pointer tracks the node behind the node we're currently on.  Initialized to null.  
		node<T>* previousNode = 0;
		//This position counter will track which index we're currently on while going through the linkedlist
		int currentPosition = 0;
		//This loop moves our pointers until we're at the correct index/position we want to insert our node at.
		//When we arrive the previousNode pointer will point to the node behind the node we're inserting
		//and the currentNode will point to the node after the node we're inserting
		while (currentPosition < position){
			//updates previous node pointer to be the current node
			previousNode = currentNode;
			//updates the current node pointer to point to the next node we're looking at
			currentNode = currentNode->next;
			//updates the current position counter to the new node
			currentPosition++;
		}
		//Create the new node we're going to insert
		node<T>* myNode = new node < T > ;
		//update the new node's value
		myNode->data = value;
		//Update the new node's pointer to point to the next node
		myNode->next = currentNode;
		//update the previous node's pointer to point to the new node rather than the old current node
		previousNode->next = myNode;
		//updates our temporary pointers to null to avoid bugs
		currentNode = 0;
		previousNode = 0;
		//update count because we have a new node
		count++;
		return;
	}
}

//This method displays the data in the front/first node
template<typename T>
T linkedList<T>::displayFront(){
	//if the list is empty, throw an error
	if (count == 0){
		throw 1;
	}
	else{
		//return the data from the front node
		return front->data;
	}
}

//This method displays the data in the end/last node
template<typename T>
T linkedList<T>::displayEnd(){
	//If the list is empty, throw an error
	if (count == 0){
		throw 1;
	}
	else{
		//return the data from the last node
		return end->data;
	}
}

//returns the value of a node at a specific index
template <typename T>
T linkedList<T>::displayValueAt(const int position){
	//If the index doesn't exist throw an error
	//Count allows this method to also throw errors if the list is empty
	if (position < 0 || position > count){
		throw 1;
	}//If the index is correct loop to the correct location and retrieve the information.
	else{
		//A pointer to track which node we're currently on
		node<T>* currentNode = front;
		//This is a counter that tracks which node index/position we've looped to thus far
		int currentPosition = 0;
		//This loop loops us to the correct node we want to return the information for
		while (currentPosition < position){
			//update the pointer to point to the next node in the chain
			currentNode = currentNode->next;
			//update the index/position
			currentPosition++;
		}
		//return the information in the node
		return currentNode->data;
	}
}

//This overloads the square brackets so we can access information in the linked list like this: myLinkedList[4];
template<typename T>
T linkedList<T>::operator[](const int position){
	return displayValueAt(position);
}

//delete the front/first node
template<typename T>
void linkedList<T>::removeFront(){
	//If the linked list is empty do nothing
	if (count == 0){
		return;
	}//If the linked list has one node it becomes empty
	else if(front == end){
		//delete the first/front node
		delete front;
		//set the front/first pointer to null
		front = 0;
		//set the last/end pointer to null
		end = 0;
		//decrement the counter back to 0
		count--;
		//exit the method since we're done
		return;
	}//Default scenario
	else{
		//create a pointer to track the first node so we can delete it
		node<T>* currentNode = front;
		//update the front pointer to point to the next node since we're deleting the first one
		front = front->next;
		//delete the first node
		delete currentNode;
		//update the currentNode pointer to be null
		currentNode = 0;
		//update the count so it knows we have one less node
		count--;
	}
}

template<typename T>
void linkedList<T>::removeEnd(){
	//If the linked list is empty do nothing
	if (count == 0){
		return;
	}//If the linked list has one node it becomes empty
	else if (front == end){
		//delete the first/front node
		delete front;
		//set the front/first pointer to null
		front = 0;
		//set the last/end pointer to null
		end = 0;
		//decrement the counter back to 0
		count--;
		//exit the method since we're done
		return;
	}//Default scenario
	else{
		//This pointer will be used to track the current node we're on
		node<T>* currentNode = front;
		//this pointer will be used to track the node behind the node we're currently on.
		//It's initially set to null
		node<T>* previousNode = 0;
		//This loop gets us to the last node and positions the previousNode pointer to the second to last node
		while (currentNode->next != 0){
			//update the previousNode pointer to be equal to the currentNode pointer
			previousNode = currentNode;
			//After updating the previousNode pointer mode the currentNode pointer forward one node
			currentNode = currentNode->next;
		}
		//Since the previousNode pointer is poointing to the new LAST/END node we update the "next" pointer to be null
		previousNode->next = 0;
		//We delete the last node
		delete currentNode;
		//after deleting the last node we update the "end" pointer in our linked list to point to the new last node
		end = previousNode;
		//Update the "count" so that it knows we have one less node
		count--;
		//exit the method
		return;
	}
}

template<typename T>
void linkedList<T>::removeAt(const int position){
	//If they try to removeAt a node that is out of bounds then do nothing
	if (position < 0 || position > count){
		//return exits the method without doing anything
		return;
	}//If they try to removeAt a node and the first pointer is null (the linked list is empty) then do nothing
	else if (front == 0){
		//return exists the method without doing anything
		return;
	}//If there is only one node in the linked list
	else if (front == end){
		//delete the first/front node
		delete front;
		//set the front/first pointer to null
		front = 0;
		//set the last/end pointer to null
		end = 0;
		//decrement the counter back to 0
		count--;
		//exit the method since we're done
		return;
	}//If they try to removeAt the last node
	else if (position == count){
		//This pointer will be used to track the current node we're on
		node<T>* currentNode = front;
		//this pointer will be used to track the node behind the node we're currently on.
		//It's initially set to null
		node<T>* previousNode = 0;
		//This loop gets us to the last node and positions the previousNode pointer to the second to last node
		while (currentNode->next != 0){
			//update the previousNode pointer to be equal to the currentNode pointer
			previousNode = currentNode;
			//After updating the previousNode pointer mode the currentNode pointer forward one node
			currentNode = currentNode->next;
		}
		//Since the previousNode pointer is poointing to the new LAST/END node we update the "next" pointer to be null
		previousNode->next = 0;
		//We delete the last node
		delete currentNode;
		//after deleting the last node we update the "end" pointer in our linked list to point to the new last node
		end = previousNode;
		//Update the "count" so that it knows we have one less node
		count--;
		//exit the method
		return;
	}//If they try to removeAt the first node
	else if (position == 0){
		//create a pointer to track the first node so we can delete it
		node<T>* currentNode = front;
		//update the front pointer to point to the next node since we're deleting the first one
		front = front->next;
		//delete the first node
		delete currentNode;
		//update the currentNode pointer to be null
		currentNode = 0;
		//update the count so it knows we have one less node
		count--;
	}//default scenario of a correct index/position and a linked list with multiple nodes
	else{
		//create a pointer "currentNode" that will track which node we're at
		node<T>* currentNode = front;
		//the "previousNode" pointer will point to the node before the current Node
		node<T>* previousNode = 0;
		//This pointer will point to the node after the current node.  
		//All three of these pointers make it easy to delete a node and then update the "next" pointers in the node
		node<T>* nextNode = 0;
		//This FOR loop loops us until we get to the node we want to delete
		for (int i = 0; i < position; i++){
			//updates previousNode pointer to be equal to the currentNode pointer
			previousNode = currentNode;
			//after updating previousNode we update the currentNode pointer to the next node
			currentNode = currentNode->next;
		}
		//update nextNode to be equal to the node after the node we're going to delete
		nextNode = currentNode->next;
		//update the previousNode's "next" pointer to point to the node after the one that we're going to delete so the linked list won't have a hole
		previousNode->next = nextNode;
		//deletes the target node
		delete currentNode;
		//updates the count so the linked list knows we have one less node
		count--;
	}
}

//searches the linked list and outputs a message confirming or denying 
template<typename T>
bool linkedList<T>::checkFor(T value){
	//this node pointer will enable to go through the list
	node<T>* temp;
	//update the pointer to the first node
	temp = front;
	//This loop goes through the linked list and tries to find a node with a matching value
	for (int i = 0; i < count; i++){
		//If we find the matching data output which node it's in and exit the method
		if (temp->data == value){
			//cout << "The value of " << value << " is in node " << i << endl;
			return true;
		}//If we don't find the matching data at this node move to the next one
		else{
			temp = temp->next;
		}
	}//If there is no matching node inform the user.
	//cout << "Unfortunately the linked list does not contain " << value << "." << endl;
	return false;
}

//A method that displays all the contents of the list
template<typename T>
void linkedList<T>::enumerate(){
		node<T>* temp;
		temp = front;
		for (int i = 0; i < count; i++){
			cout << "Node " << i << ": " << temp->data << endl;
			temp = temp->next;
		}
}

//Below are the simple tests of all the methods of the linked list
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
	//Adding "10" to the 3rd position.  List is now: 19->17->10->15->5
	myLinkedList.addAt(2, 10);
	//enumerate displays all the contents of our linked list
	myLinkedList.enumerate();
	cout << myLinkedList.displayValueAt(0) << endl;
	cout << myLinkedList[0] << endl;;
	//linked list checks and confirms that the linked list contains 15
	cout << "Does the linked list contain 15? " << myLinkedList.checkFor(15) << endl;
	//linked list checks and denies that the linked list contains 64
	cout << "Does the linked list contain 64? " << myLinkedList.checkFor(64) << endl;
	//removing 10, the linked list should now read 19->17->15->5
	myLinkedList.removeAt(2);
	//This one will do nothing since -1 isn't a valid index
	myLinkedList.removeAt(-1);
	//This one will do nothing since 15 isn't a valid index
	myLinkedList.removeAt(15);
	myLinkedList.enumerate();
	myLinkedList.addFront(3);
	myLinkedList.addFront(2);
	myLinkedList.addFront(1);
	myLinkedList.enumerate();
	myLinkedList.addEnd(1);
	myLinkedList.addEnd(2);
	myLinkedList.addEnd(3);
	myLinkedList.enumerate();
	cout << "Front node is: " << myLinkedList.displayFront() << " and end node is: " << myLinkedList.displayEnd() << endl;
	myLinkedList.removeFront();
	myLinkedList.removeEnd();
	myLinkedList.enumerate();

	//destructor frees up the memory that was used by our nodes in the linked list
	myLinkedList.~linkedList();
	_getch();
	return 0;
}