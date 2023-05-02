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
	
	void reverse_traversal ( Node *head ){
		Node *ptr = head;
		do{
			ptr = ptr->next;
			cout << "Element: " << ptr->data << endl;
		}while(ptr!=head);
	}
	
	Node* CreateHead ( int d ){
		Node *head = new Node;
		head->next = head;
		head->data = d;
	}
	
	Node* AddToTail ( Node *head, int d ){
		Node *NewNode = new Node;	
		Node *ptr = head;
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		ptr->next = NewNode;
		NewNode->data = d;
		NewNode->next = head;
		return head;
	}
	
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
};

int main (){
	//Head Created
	Node *head, *temp;
	cout << "---Head Created---\n";
	head = head->CreateHead(1);
	temp = temp->CreateHead(1);
	head->linkedlist_traversal(head);
	
	//Add Nodes at Tail
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,2);
	temp = temp->AddToHead(temp,2);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,3);
	temp = temp->AddToHead(temp,3);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToTail(head,4);
	temp = temp->AddToHead(temp,4);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToTail(head,5);
	temp = temp->AddToHead(temp,5);
	head->linkedlist_traversal(head);
	
	cout << "\n---Reverse---\n";
	head->linkedlist_traversal(temp);
	return 0;
}

