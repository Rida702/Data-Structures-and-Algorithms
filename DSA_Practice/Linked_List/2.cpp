#include<iostream>
using namespace std;

//Node insertion
//A Node can be added in four ways 
//1. At the Front(head) of the linked list
//2. At the End of the Linked List
//3. After a given Node
//4. Before a given Node

//If the new Node is the First Node in the list that is a Special Case, Handle it Carefully!!

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

class List {
	Node* head;
public:	
	void insertAtEnd(int data){
		Node* newNode = new Node(data,NULL);
		//if first node is added
		if(head==NULL) head = newNode;
		//if the list already have nodes, find the last node first
		else {
			Node* curNode = head;
			while(curNode->next!=NULL)
				curNode = curNode->next;
			curNode->next = newNode;
		}
	}
	
	//Traversing in Linked List
	//Visiting or Accessing the data of Nodes
	void Traverse (){
		if(head==NULL) cout << "LIST IS EMPTY\n";
		else{
			Node* curNode=head;
		do{
			cout << curNode->data << " ";
			curNode = curNode->next;
		}while(curNode!=NULL);
		}
	}
	
	//Node Removal and Destructor
	//Let's Consider atleast 3 cases 
	//1. Removing a Node from beginning (head)
	//2. Removing the Last Node
	//3. Removing a Specific Node (key value)
	void removeLast ( ){
		if(head->next==NULL){
		delete head;
		head = NULL;
	}
	else {
		Node* preNode = head;
		Node* curNode = head->next;
		while(curNode->next!=NULL){
			preNode = curNode;
			curNode = curNode->next;
		}
		delete curNode;
		preNode->next = NULL;
	}
}

//Linked List Destructor
//It is important to write destructor for linked list as all the nodes are created dynamically on heap
//We have to remove all the Nodes ourselves to avoid memory leaks
	~List (){
		if(head!=NULL){
			Node* curNode = head;
			while ( curNode->next!=NULL){
				head = curNode->next;
				delete curNode;
				curNode = head;
			}
			delete head;
		}
	} 


};

int main(){
	List l1;
	l1.insertAtEnd(10);
	l1.Traverse();
	cout <<endl;
	l1.insertAtEnd(120);
	l1.insertAtEnd(140);
	l1.insertAtEnd(150);
	l1.Traverse();
	cout <<endl;
	l1.removeLast();
	l1.removeLast();
	l1.Traverse();
	return 0;
}
