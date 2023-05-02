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
	Node *temp = new Node;
	int num, data;
	cout << "Test Data\n";
	cout << "Input the number of nodes: ";
	cin >> num;
	for ( int i=0; i<num; i++){
		if (i==0){
		cout << "Input data for node " << i+1 << " :";
		cin >> data;
		head = n1.addToHead(data);
		temp = head;
	}	
	else {
		cout << "Input data for node " << i+1 << " :";
		cin >> data;
		temp = n1.addToEnd(data, temp);
	}
	
}

cout << "\nExpected Output: " << endl;
cout << "--Data Entered in the List: " << endl;
	n1.linkedlist_traversal(head);
	
cout << "Input data to insert at the beginning of the list :";
cin >> data;
temp = n1.addtoStart(data, head);
cout << "Data after inserted in the list are: " << endl;
n1.linkedlist_traversal(temp);

	return 0;
}
