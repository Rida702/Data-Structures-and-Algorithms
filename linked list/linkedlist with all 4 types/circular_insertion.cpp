//creation and traversal in Circular linked list
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	void linkedlist_traversal ( Node *head ){
		Node *ptr = head;
		do{
			cout << "Element: " << ptr->data << endl;
			ptr = ptr->next;
			
		}while(ptr!=head);
	}
	
//Creating head	
	Node* CreateHead ( int d ){
		Node *head = new Node;
		head->next = head;
		head->data = d;
	}
	
	
//Adding nodes at tail/End
	Node* AddToTail ( Node *head, int d ){
		Node *NewNode = new Node;	
		Node *ptr = head;
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		ptr->next = NewNode;
		NewNode->data = d;
		NewNode->next = head;
		return NewNode;
	}

//Adding nodes at Start/Head	
	Node* AddToHead ( Node *head, int d ){
		Node *NewNode = new Node;
		Node *ptr = head;
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		NewNode->data = d;
		NewNode->next = head;
		ptr->next = NewNode; 
		return NewNode;
	}
	
//Adding Nodes in the middle
	Node* insertInBtw ( Node *head, int d, int index ){
		Node *NewNode = new Node;
		Node *ptr = head;
		int i=0;
		while (i!=index-1){
			ptr = ptr->next;
			i++;
		}
		NewNode->data = d;
		NewNode->next = ptr->next; 
		ptr->next = NewNode;
		return head;
	}
		
//Insert after the node	
	Node* insertAfterNode ( Node *head , Node *prevNode, int d ){
		Node *NewNode = new Node;
		NewNode->data = d;
		NewNode->next = prevNode->next;
		prevNode->next = NewNode;
		return head;
	}
};

int main (){
	//Head Created
	cout << "\n\t\t-*-*-*<Circular Linked List>*-*-*-\n";
	Node *head, *second, *third;
	cout << "---Head Created---\n";
	head = head->CreateHead(7);
	second = head->AddToTail(head, 11);
	third = head->AddToTail(head,99);
	
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion at the beginning--\n";
	head = head->AddToHead(head,67);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion In the Middle--\n";
	head = head->insertInBtw(head, 55, 2);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion At the End--\n";
	head = head->AddToTail(head, 33);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion after a Node-> data = 11 --\n";
	head = head->insertAfterNode(head, second, 441);
	head->linkedlist_traversal(head);
}
