//creation and traversal in Circular linked list
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	void linkedlist_traversal ( Node *head ){
		Node *ptr = head;
		int i=1;
		do{
			cout << "Element " << i << " : " << ptr->data << endl;
			i++;
			ptr = ptr->next;
			
		}while(ptr!=head);
	}
	
	void reverse_traversal ( Node *head ){
		Node *ptr = head;
		int i=1;
		do{
			
			ptr = ptr->next;
			cout << "Element " << i << " : " << ptr->data << endl;
			i++;
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
	
	Node* DeleteHead ( Node *head ){
		Node *ptr = head;
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		head = head->next;
		ptr->next = head;
		return ptr->next;
	}
	
	Node* DeleteFromMiddle ( Node *head, int index ){
		Node *p = head;
		Node *q = head->next;
		int i=0;
		while(i!=index-1){
			p=p->next;
			q=q->next;
			i++;
		}
		p->next = q->next;
		delete q;
		return head;
	}
	
	Node* DeleteAtEnd ( Node *head ){
		Node *p = head;
		Node *q = head->next;
		while ( q->next!=head ){
			p = p->next;
			q = q->next;
		}
		p->next = head;
		delete q;
		return head;
	}
	
	Node* DeleteAvalue ( Node *head, int value ){
		Node *p = head;
		Node *q = head->next;
		while ( q->data!=value ){
			p = p->next;
			q = q->next;
		}
		p->next=q->next;
		delete q;
		return head;
	}
	
};

int main (){
	//Head Created
	cout << "\n\t\t-*-*-*<Circular Linked List>*-*-*-\n";
	Node *head;
	cout << "---Head Created---\n";
	head = head->CreateHead(1);
	head->linkedlist_traversal(head);
	
	//Add Nodes at Tail
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,2);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Tail---\n";
	head = head->AddToTail(head,3);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToHead(head,4);
	head->linkedlist_traversal(head);
	
	cout << "\n---Add to Head---\n";
	head = head->AddToHead(head,5);
	head->linkedlist_traversal(head);
	
	int choice;
	char option;
	do{
	cout << "Enter a number b/w 1-4: ";
	cin >> choice;
	 
	if ( choice==1 )		head = head->DeleteHead(head);
	else if ( choice==2 ) 	{
		head = head->DeleteFromMiddle(head,3);
		cout << "Deleting 3rd index:\n";
	}
	else if ( choice==3 ) 	head = head->DeleteAtEnd(head);
	else if ( choice==4 )	head = head->DeleteAvalue(head,1);
	
	cout << "List after Deletion: " << endl;
	head->linkedlist_traversal(head);
	cout << "Press Y to continue and n to exit\n";
	cin >> option;
	}while(option!='n');
}

