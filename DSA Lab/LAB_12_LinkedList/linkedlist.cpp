#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
public:
	Node ( int data, Node* next ){
		this->data = data;
		this->next = next;
	}
	friend class LinkedList;
};

class LinkedList{
private:
	Node* head;
public:
	LinkedList (){
		head = NULL;
	}
	bool isEmpty (){
		return (head==NULL);
	}
	
	void InsertAtEnd ( int data ){
		Node* temp = new Node(data, NULL);
		if( head==NULL) head = temp;
		else {
			Node* cur = head;
			while(cur->next!=NULL) {
				cur = cur->next;
			}
			cur->next = temp;
		}
	}
	
	void InsertAtStart ( int data ){
		Node* cur = head;
		Node* temp = new Node(data, NULL);
		if( head==NULL ) head = temp;
		else{
			temp->next = head;
			head = temp;
		}
	}
	
	void ShowData ( ){
		Node* temp = head;
		if(head==NULL) cout << "Linked List is Empty" << endl;
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
	~LinkedList ( ){
		Node* cur = head;
		while( cur!=NULL ){
			cur = cur->next;
			delete head;
			head = cur ;
		}
	}
};

int main(){
	LinkedList list1;
	list1.ShowData();
	list1.InsertAtEnd(6);
	list1.InsertAtEnd(5);
	list1.InsertAtStart(88);
	list1.ShowData();
	return 0;
}
