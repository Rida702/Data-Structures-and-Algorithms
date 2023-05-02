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
	Node *head, *second, *third, *tail;
	
	//Allocate memory for nodes in the linked lists
	head   = new Node;
	second = new Node;
	third  = new Node;
	tail  = new Node;
	
	//link 1st and 2nd node
	head->data = 11;
	head->next = second;
	
	//link 2nd and 3rd node
	second->data = 22;
	second->next = third;
	
	//Terminate the list at the third node
	third->data = 33;
	third->next = head;
	
	//linked list traversal
	head->linkedlist_traversal(head);
	cout << "\n-----Add to Tail------\n";
	head = head->AddToTail(head,44);
	head->linkedlist_traversal(head);
	
	cout << "\n-----Add to Tail------\n";
	head = head->AddToTail(head,55);
	head->linkedlist_traversal(head);
	
	cout << "\n-----Add To Head------\n";
	head = head->AddToHead(head,66);
	head->linkedlist_traversal(head);
	
	cout << "\n-----Add To Head------\n";
	head = head->AddToHead(head,77);
	head->linkedlist_traversal(head);
	return 0;
}
