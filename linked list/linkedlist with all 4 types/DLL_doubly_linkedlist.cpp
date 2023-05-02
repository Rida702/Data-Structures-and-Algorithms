//creation and traversal in Circular linked list
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *prev;
	Node *next;
	
	void linkedlist_traversal ( Node *head ){
		Node *ptr = head;
		//cannot use ptr->next!=NULL, because if ptr/Node is already NULL how can you even point to its next
		while(ptr!=NULL){
			cout << "Element: " << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	
	Node* CreateHead ( int d ){
		Node *head = new Node;
		head->next = NULL;
		head->prev = NULL;
		head->data = d;
		return head;
	}
	
	Node* AddToTail ( Node *head, int d ){
		Node *NewNode = new Node;
		Node *ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}					
		ptr->next = NewNode;
		NewNode->prev = ptr;
		NewNode->next = NULL;
		NewNode->data = d;
		return head;
	}
	
	Node* AddToHead ( Node *head, int d ){
		//whether u use ptr in this case or not u have created the links of Nodes
		//No matter by using which ever variable
		Node *NewNode = new Node;
		Node *ptr = head;
		NewNode->data = d;
		NewNode->prev = NULL;
		NewNode->next = ptr;
		ptr->prev = NewNode;
		return NewNode;
	}
};

int main (){
	//Head Created
	cout << "\n\t\t-*-*-*<Doubly Linked List>*-*-*-\n";
	string success;
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

