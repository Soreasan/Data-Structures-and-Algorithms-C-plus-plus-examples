#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

/*************************************************************************
Hash Table Code START
*************************************************************************/
const int HASH_TABLE_SIZE = 100;

class HashTable {
private:
	//Basically an array of linked lists.  
	//Need to use pointers since C++ is funky and won't 
	//just let me initialize an array of linked lists without some pointers.
	linkedList ** my;
public:
	HashTable(); //constructor
	~HashTable(); //destructor
};

//constructor
HashTable::HashTable(){
	/*
	table = new linkedList<string>*[HASH_TABLE_SIZE];
	for (int i = 0; i < HASH_TABLE_SIZE; i++){
		table[i] = new linkedList < string > ;
	}*/
};

//destructor
HashTable::~HashTable(){
	/*
	for (int i = 0; i < HASH_TABLE_SIZE; i++){
		delete table[i];
	}*/
};
/*************************************************************************
Hash Table Code END
*************************************************************************/


/*************************************************************************
	Linked List Code START
*************************************************************************/
struct node{
	string data;
	node* next;
};

class linkedList{
public:
	linkedList();	//constructor
	~linkedList();	//destructor
	void add(string value); //Adds a value to the end
	void remove(string value); //Removes the value from the linked list by the value
	string get(string value); //return a node's data by value
	bool checkFor(string value);	//Checks the linked list to see if it contains a specific value

private:
	node* front;	//this pointer points to the node at the front
	node* end;		//this pointer points to the last node
	int count;		//This tracks how many nodes are in our linked list	
};

//constructor
linkedList::linkedList(){
	//To set a pointer to null you can either make it = 0 or make it = NULL
	front = 0;
	end = 0;
	count = 0;
};

//destructor, deletes all nodes
linkedList::~linkedList(){
	node* temp;
	while (front != 0){
		temp = front;
		front = front->next;
		delete temp;
	}
	end = 0;
	count = 0;
};

//Adds a node to the end.  
void linkedList::add(string value){
	node *myNode = new node();
	myNode->data = value;
	count++;
	if (count == 1){
		front = myNode;
	}
	else{
		end->next = myNode;
	}
	end = myNode;
};

//Removes a node by value
void linkedList::remove(string value){
	//If the linked list is empty, do nothing
	if (count == 0){
		return;
	}
	//Next search the list and see if we can find the node
	node * curr = front;
	node * prev = front;
	//Find the node or go to the end
	while (curr->data != value && curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	//If we're on the last node return and do nothing
	if (curr->data != value && curr->next != NULL){
		return;
	}
	//If there is one node, delete it
	else if (curr == front && curr == end){
		delete front;
		front = 0;
		end = 0;
		count--;
		return;
	}//If they try to removeAt the last node
	else if (curr == end){
		//Since the previousNode pointer is pointing to the new LAST/END node we update the "next" pointer to be null
		prev->next = 0;
		//We delete the last node
		delete curr;
		//after deleting the last node we update the "end" pointer in our linked list to point to the new last node
		end = prev;
		//Update the "count" so that it knows we have one less node
		count--;
		//exit the method
		return;
	}
	else{
		prev->next = curr->next;
		delete curr;
		count--;
	}
};

//Checks our linked list to see if it contains a node
bool linkedList::checkFor(string value){
	node* temp;
	temp = front;
	for (int i = 0; i < count; i++){
		if (temp->data == value){
			return true;
		}
		else{
			temp = temp->next;
		}
	}
	return false;
};

string linkedList::get(string value){
	//If the linked list is empty throw an error
	if (count == 0){
		return "no string found";
	}
	node* temp = front;
	while (temp->data != value && temp->next != NULL){
		temp = temp->next;
	}
	//If the node we got to isn't the right node and there isn't another node, throw an error
	if ((temp->data != value && temp->next)){
		return "no string found";
	}
	else{
		return temp->data;
	}
	
};

/*************************************************************************
Linked List Code END
*************************************************************************/

/*************************************************************************
int main()
*************************************************************************/
int main(){
	linkedList my;
	//valid add
	my.add("myString");
	//valid checkFor
	if (my.checkFor("myString")){
		cout << "Found 15 in the array" << endl;
	}
	//valid get
	cout << my.get("myString") << endl;
	//valid remove
	my.remove("myString");
	//invalid remove
	my.remove("myString");
	_getch();
	return 0;
}