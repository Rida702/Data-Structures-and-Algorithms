#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	
Node* addToHead ( int d){
	Node *Head = new Node;
	Head->data = d;
	Head->next = NULL;
	return Head;
}

Node* addToEnd ( int d, Node *Head){
	Node *NewNode = new Node;
	NewNode->data = d;
	Head->next = NewNode;
	NewNode->next = NULL;
	return NewNode;
}

Node* addtoStart ( int d, Node *Head){
	Node *NewNode = new Node;
	NewNode->data = d;
	NewNode->next = Head;
	return NewNode;
}

void linkedlist_traversal ( Node *ptr){
	while(ptr!=NULL){
		cout << "Data= " << ptr->data << endl;
		ptr = ptr->next;
	}
}


};


int main (){
	Node n1;
	Node *head = new Node;
	Node *tail = new Node;
	Node *temp = new Node;
	int num, data;
	cout << "Test Data\n";
	cout << "Input the number of nodes: ";
	cin >> num;
	//To create Nodes and get data
	for ( int i=0; i<num; i++){
		if (i==0){
		cout << "Input data for node " << i+1 << " :";
		cin >> data;
		head = n1.addToHead(data);
		temp = head;
		tail = n1.addToHead(data);
	}	
	else {
		cout << "Input data for node " << i+1 << " :";
		cin >> data;
		temp = n1.addToEnd(data, temp);
		tail = n1.addtoStart(data, tail);
	}
	
}

//Displaying the added Nodes
	cout << "\nExpected Output: " << endl;
	cout << "--Data Entered in the List are: " << endl;
	n1.linkedlist_traversal(head);

//Reversing the data
	cout << "The List in the Reverse are: " << endl;
	cout << "--Data Entered in the List are: " << endl;
	n1.linkedlist_traversal(tail);
	return 0;
}
