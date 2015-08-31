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

int main(){
	cout << "This will be a doubly linked list" << endl;
	_getch();
	return 0;
}