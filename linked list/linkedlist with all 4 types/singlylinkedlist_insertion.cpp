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
//Insert Before Head	
	Node* insertAthead ( Node *head , int d ){
		Node *ptr = new Node;
		ptr->data = d;
		ptr->next = head;
		return ptr;
	} 

//Insert at a given Index	
	Node* insertInBtw ( Node *head , int d , int index){
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

//insert at the end of list	
	Node* insertAtend ( Node *head , int d ){
		Node *NewNode = new Node;
		Node *ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = NewNode;
		NewNode->data = d;
		NewNode->next = NULL;
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
	Node *head, *second, *third;
	
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
	
	cout << "\n--Insertion at the beginning--\n";
	head = head->insertAthead(head, 67);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion In the Middle--\n";
	head = head->insertInBtw(head, 55, 2);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion At the End--\n";
	head = head->insertAtend(head, 33);
	head->linkedlist_traversal(head);
	
	cout << "\n--Insertion after a Node--\n";
	head = head->insertAfterNode(head, second, 441);
	head->linkedlist_traversal(head);
	return 0;
}
