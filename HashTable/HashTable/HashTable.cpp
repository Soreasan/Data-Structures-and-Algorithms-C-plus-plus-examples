#include <iostream>
#include <conio.h>
using namespace std;

/*************************************************************************
	Linked List Code START
*************************************************************************/
template<typename T>
struct node{
	T data;
	node* next;
};

template<typename T>
class linkedList{
public:
	linkedList();	//constructor
	~linkedList();	//destructor
	void add(const T& value); //Adds a value to the end
	void remove(const T& value); //Removes the value from the linked list by the value
	T get(const T& value); //return a node's data by value
	bool checkFor(T value);	//Checks the linked list to see if it contains a specific value

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

//destructor, deletes all nodes
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

//Adds a node to the end.  
template<typename T>
void linkedList<T>::add(const T& value){
	node<T> *myNode = new node<T>();
	myNode->data = value;
	count++;
	if (count == 1){
		front = myNode;
	}
	else{
		end->next = myNode;
	}
	end = myNode;
}

//Removes a node by value
template<typename T>
void linkedList<T>::remove(const T& value){
	//If the linked list is empty, do nothing
	if (count == 0){
		return;
	}
	//Next search the list and see if we can find the node
	node<T> * curr = front;
	node<T> * prev = front;
	//Find the node or go to the end
	while (curr->data != value && curr->data){
		prev = curr;
		curr = curr->next;
	}
	//If we're on the last node return and do nothing
	if (curr->data != value && curr->data){
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
		//Since the previousNode pointer is poointing to the new LAST/END node we update the "next" pointer to be null
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
}

//Checks our linked list to see if it contains a node
template<typename T>
bool linkedList<T>::checkFor(T value){
	node<T>* temp;
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
}

//returns the value of a node by value.  
template <typename T>
T linkedList<T>::get(const T& value){
	//If the linked list is empty throw an error
	if (count == 0){
		throw 1;
	}
	node<T>* temp = front;
	while (temp->data != value && temp->next != NULL){
		temp = temp->next;
	}
	//If the node we got to isn't the right node and there isn't another node, throw an error
	if ((temp->data != value && temp->next)){
		throw 1;
	}
	else{
		return temp->data;
	}
	
}

/*************************************************************************
Linked List Code END
*************************************************************************/

/*************************************************************************
int main()
*************************************************************************/
int main(){
	linkedList<int> my;
	//valid add
	my.add(15);
	//valid checkFor
	if (my.checkFor(15)){
		cout << "Found 15 in the array" << endl;
	}
	//valid get
	cout << my.get(15) << endl;
	//valid remove
	my.remove(15);
	//invalid remove
	my.remove(15);
	_getch();
	return 0;
}