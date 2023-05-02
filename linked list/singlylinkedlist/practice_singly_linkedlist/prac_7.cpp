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
 
int searchNode( int d, Node *Head){
	int count=0;
	while (Head!=NULL){
		count++;
		if(Head->data == d) goto end;
		Head = Head->next;
	}
	end:
		return count;
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
		temp = n1.addNode(data, temp);
	}
	
}

cout << "\nExpected Output: " << endl;
cout << "--Data Entered in the List: " << endl;
	n1.linkedlist_traversal(head);
	
//Searching element
cout << "Input the element to be searched :";
cin >> data;
cout << "Element found at node " << n1.searchNode(data, head) << endl;

	return 0;
}
