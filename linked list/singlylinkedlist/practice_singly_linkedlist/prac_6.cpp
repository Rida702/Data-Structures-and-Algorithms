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

Node* addNode ( int d, Node *Head){
	Node *NewNode = new Node;
	NewNode->data = d;
	Head->next = NewNode;
	NewNode->next = NULL;
	return NewNode;
}
 
Node* DeleteFromHead( Node *Head){
	Node *NewHead = new Node;
	NewHead = Head->next;
	delete []Head;
	Head = NewHead;
	return Head;
	
	/*Node *NewHead = new Node;
	NewHead = Head->next;
	return NewHead;*/
}

Node* DeleteFromMiddle( Node *Head, int index ){
	Node *ptr = Head;
	Node *ptr1;
	int i=0;
	while(i!=index){
		ptr = ptr->next;
		i++;
		if(i==(index-1	))		ptr1 = ptr;
	}
	ptr1->next = ptr->next;
	ptr1->data = ptr->data;
	delete[]ptr;
	return Head; 
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
	int num, data, position;
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
		temp = n1.addNode(data, temp);
	}
	
}

cout << "\nExpected Output: " << endl;
cout << "--Data Entered in the List: " << endl;
n1.linkedlist_traversal(head);
	
//Delete from the middle
cout << "Input the position of node to delete: ";
cin >> position;
head = n1.DeleteFromMiddle(head, position);
cout << "\nDeletion completed successfully.\n";
n1.linkedlist_traversal(head);
	return 0;
}
