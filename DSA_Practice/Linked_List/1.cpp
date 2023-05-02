#include<iostream>
using namespace std;

//Singly Linked List
class Node {
	int data;
	Node* next; //Inside class you can take a class type pointer object is not allowed
public:
	Node ( int data, Node* next){
		this->data = data;
		this->next = next;
	}
	//Node class becomes public to list
	friend class List;
};

//The Node class will create nodes only we need another class to link them
//the data member which will hold the list is *head pointer
class List {
	Node* head;
public:
	List(){
		head = NULL; //initially the list is empty
	}
	
	bool isEmpty(){
		return !head; //if list is empty head contains zero (false)
	}
	//No need of isFull function as we are creating elements on demand
};

int main(){
	List l1;
	bool result = l1.isEmpty();
	if(result) cout << "List is Empty\n";
	else "List is not empty\n";
	return 0;
}
