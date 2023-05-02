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

Node* addTomiddle ( Node *head , int d , int index ){
	Node *NewNode = new Node;
		Node *ptr = head;
		int i=1;
		while (i!=index-1){
			ptr = ptr->next;
			i++;
		}
		NewNode->data = d;
		NewNode->next = ptr->next; 
		ptr->next = NewNode;
		return head;
}

};


int main (){
	Node n1;
	Node *head = new Node;
	Node *temp = new Node;
	int num, data, position;
	cout << "Test Data\n";
	cout << "Input the number of nodes(3 or more): ";
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

//Display List
cout << "\nExpected Output: " << endl;
cout << "--Data Entered in the List: " << endl;
	n1.linkedlist_traversal(head);

//Inserting in the middle
cout << "Input data to insert in the middle of the list :";
cin >> data;
cout << "Input the position to insert new node :";
cin >> position;

//Displaying after inserting
head = n1.addTomiddle(head, data, position);
cout << "\nInsertion Completed Successfully\n";
cout << "the new list are: " << endl;
n1.linkedlist_traversal(head);

	return 0;
}
