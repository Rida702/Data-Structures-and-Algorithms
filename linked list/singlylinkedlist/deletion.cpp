//creation and traversal in linked list
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
	
	Node* DeleteHead ( Node *head ){
		Node *NewNode = head;
		NewNode = head->next;
		delete[]head;
		head = NewNode;
		return head;
		
		/*Node *NewNode = head;
		head = head->next;
		delete[]NewNode;
		return head;*/
	}
	
	Node* DeleteFromMiddle ( Node *head, int index ){
		Node *p = head;
		Node *q = head->next;
		for ( int i=1; i<index-1; i++){
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		delete[]q;
		return head;
	}
	
	Node* DeleteAtEnd ( Node *head ){
		Node *p = head;
		Node *q = head->next;
		while(q->next!=NULL){
			p=p->next;
			q=q->next;
		}
		p->next = NULL;
		delete[]q;
		return head;
	}
	
	Node* DeleteAvalue ( Node *head, int value ){
		Node *p = head;
		Node *q = p->next;
		while ( q->data!=value ){
			p=p->next;
			q=q->next;
			if(q->next != NULL){
            continue;
        }
	}
		if ( q->data==value){
			p->next == q->next;
			delete q; 
		}
		else cout << "This value doesn't exist in the given Linked List." << endl;
		return head;
	}
};

int main (){
	Node *head, *second, *third, *fourth, *fifth;
	
	//Allocate memory for nodes in the linked lists
	head   = new Node;
	second = new Node;
	third  = new Node;
	fourth  = new Node;
	fifth  = new Node;
	
	//link 1st and 2nd node
	head->data = 11;
	head->next = second;
	
	//link 2nd and 3rd node
	second->data = 22;
	second->next = third;
	
	//Terminate the list at the third node
	third->data = 33;
	third->next = fourth;
	
	fourth->data = 44;
	fourth->next = fifth;
	
	fifth->data = 55;
	fifth->next = NULL;
	
	//linked list traversal
	head->linkedlist_traversal(head);
	
	//Deletion
	int choice;
	cout << "Enter a number b/w 1-4: ";
	cin >> choice;
	 
	if ( choice==1 )		head = head->DeleteHead(head);
	else if ( choice==2 ) 	head = head->DeleteFromMiddle(head,3);
	else if ( choice==3 ) 	head = head->DeleteAtEnd(head);
	else if ( choice==4 )	head = head->DeleteAvalue(head,22);
	
	cout << "List after Deletion: " << endl;
	head->linkedlist_traversal(head);
	return 0;
}
