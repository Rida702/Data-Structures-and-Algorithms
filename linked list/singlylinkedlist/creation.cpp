//creation and traversal in singly linked list
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	void linkedlist_traversal ( Node *ptr){
		while(ptr!=NULL){
			cout << "Element: " << ptr->data << endl;
			ptr = ptr->next;
		}
	}
};

int main (){
	Node *head, *second, *third;
	cout << "\n\t\t-*-*-*<Singly Linked List>*-*-*-\n";
	//Allocate memory for nodes in the linked lists
	head   = new Node;
	second = new Node;
	third  = new Node;
	
	//link 1st and 2nd node
	head->data = 7;
	head->next = second;
	
	//link 2nd and 3rd node
	second->data = 11;
	second->next = third;
	
	//Terminate the list at the third node
	third->data = 99;
	third->next = NULL;
	
	//linked list traversal
	head->linkedlist_traversal(head);
	return 0;
}
