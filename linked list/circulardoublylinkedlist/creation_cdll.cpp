//creation and traversal in Circular Doubly linked list
//cout << "ptr->next: " << ptr->next << endl;
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *prev;
	Node *next;
	
	void linkedlist_traversal ( Node *head ){
		Node *ptr = head;
		do{
			cout << "Element: " << ptr->data << endl;
			ptr = ptr->next;
			
		}while(ptr!=head);
	}
	
	Node* CreateHead ( int d ){
		Node *head = new Node;
		head->next = head;
		head->prev = head;
		head->data = d;
	}
	
	Node* AddToTail ( Node *head, int d ){
		Node *NewNode = new Node;
		Node *ptr = head->prev;
		if(head->next == head || head->prev == head)		head->next = NewNode;		
		else												ptr->next = NewNode;
		NewNode->prev = ptr;
		NewNode->next = head;
		head->prev = NewNode;
		NewNode->data = d;
		return head;
	}
	
	Node* AddToHead ( Node *head, int d ){
		Node *NewNode = new Node;
		Node *ptr = head->prev;
		ptr->next = NewNode;
		NewNode->prev = head->prev;
		NewNode->next = head;
		head->prev = NewNode;
		NewNode->data = d;
		return NewNode;
	}
};

int main (){
	//Head Created
	cout << "\n\t\t-*-*-*<Circular Doubly Linked List>*-*-*-\n";
	Node *head;
	cout << "---Head Created---\n";
	head = head->CreateHead(33);
	head->linkedlist_traversal(head);
	
	//Add Nodes at Tail
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,44);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,55);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToHead(head,22);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToHead(head,11);
	head->linkedlist_traversal(head);
}

