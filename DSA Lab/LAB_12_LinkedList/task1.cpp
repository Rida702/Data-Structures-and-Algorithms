#include<iostream>
#include<fstream>
using namespace std;

class Student { 
private: 
	int id; 
	string name;
	float cgpa; 
	Student* next;
public: 
Student(int id, string name, float cgpa, Student *next){
	this->id = id;
	this->name = name;
	this->cgpa = cgpa;
	this->next = next;
}
void studentDetails(){
	cout << "Student ID: " << this->id << endl;
	cout << "Student Name: " << this->name << endl;
	cout << "Student CGPA: " << this->cgpa << endl;
	cout << "-----\n";
}
friend class StudentList; 
}; 

class StudentList{ 
private: 
	Student* head; 
	Student* cursor;
public: 
	StudentList(){
		head = NULL;
		cursor = NULL;
	}
	
void insert ( Student* newStd  ) {
	if( head==NULL ) {
		head = newStd;
		cursor = newStd;	
	}
	else {
		Student* cur = head;
		while(cur->next!=NULL) {
			cur = cur->next;
		}
		cur->next = newStd;
		cursor = newStd;
	}
}
	
void ShowData ( ){
	Student* temp = head;
	if(head==NULL) cout << "Linked List is Empty\n" << endl;
	while(temp!=NULL){
		temp->studentDetails();
		temp = temp->next;
	}
}

//cout << "Head: " << head << endl;
//cout << "cursor: " << cursor << endl;
//cout << "temp: " << temp << endl;

void remove (int id){
	Student* temp = head;
	if(head==NULL) cout << "Linked List is Empty\n" << endl;
	else if ( cursor->id==id ){
		while(temp->next!=cursor){
				temp=temp->next;	}
		if( cursor->next==NULL )	temp->next = NULL;
		else 						{
			temp->next = cursor->next;
			delete cursor;
			cursor = temp;
		}
	}
	else {
		Student* prev = head;
		while(temp->id!=id){
		prev = temp;
		temp = temp->next;
	}
		prev->next = temp->next;
		delete temp;
	}
} 

void search (float cgpa) const {
	int flag = 0;
	Student* cur = head;
	while(cur!=NULL){
		if(cur->cgpa==cgpa)cur->studentDetails();
		cur = cur->next;
		flag=1;
	}
	if( flag==0 ) cout << "No Record Found\n";
}
	
void replace (Student* newStd) {
	int flag = 0;
	Student* cur = head;
	while(cur!=NULL){
		if(cur->id==newStd->id) {
		cur->name = newStd->name;
		cur->cgpa = newStd->cgpa;
		flag=1;
		break;
		}
		cur = cur->next;
	}
	if( flag==0 ) {
		cur->id = newStd->id;
		cur->name = newStd->name;
		cur->cgpa = newStd->cgpa;
	}
		cursor = newStd;
}	

bool isEmpty () const{
	return (head==NULL);
}

void gotoBeginning () {
	cursor = head;
}

void gotoEnd () {
	Student* cur = head;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cursor = cur;
}

bool gotoNext () {
	if(cursor->next==NULL) {
		return false;
	}
	else {
		Student* cur = head;
		while (cur!=cursor){
			cur = cur->next;
		}
		cursor = cur->next;
		return true;
	}
}

bool gotoPrior () {
	if(cursor==head) {
		return false;
	}
	else {
		Student* cur = head;
		while (cur->next!=cursor){
			cur = cur->next;
		}
		cursor = cur;
		return true;
	}
}

Student getCursor () {
	cout << "\n---DATA AT CURSOR: \n";
	cout << "ID: " << cursor->id << endl;
	cout << "Name: " << cursor->name << endl;
	cout << "CGPA: " << cursor->cgpa << endl;
	cout << "-----\n";
}

void showStructure () const {
	Student* temp = head;
	if(head==NULL) cout << "Linked List is Empty\n" << endl;
	while(temp!=NULL){
		temp->studentDetails();
		temp = temp->next;
	}
}
	
~StudentList(){
	Student* cur = head;
	while( cur->next!=NULL ){
		cur = cur->next;
		delete head;
		head = cur;
	}
	delete cursor;
}
}; 

int main (){
	StudentList s1;
	s1.ShowData();
	ifstream my_file("input.txt");
	int id; 
	string name, n;
	float cgpa; 
	while(my_file.good()){
		my_file >> id;
		my_file >> name;
		my_file >> cgpa;
		Student *s = new Student(id,name,cgpa,NULL);
		s1.insert(s);
	}
	s1.ShowData();
	my_file.close();
	
	cout << "\nDeleting a Student's Data: \n";	
	//Deleting at Cursor
//	s1.remove(10);
//	s1.ShowData();
	//Deleteing From In Between
//	s1.remove(6);
//	s1.ShowData();

	cout << "\nSearching a Student's Data: \n";	
	s1.search(3.22);
	
	cout << "Adding new Data: \n";
	cout << "Enetr ID: ";
	cin >> id;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter CGPA: ";
	cin >> cgpa;
	Student *ss = new Student(id,name,cgpa,NULL);
	s1.replace(ss);
	s1.ShowData();
	
	cout << "\nChecks if a List is Empty\n";
	if( s1.isEmpty() ) cout << "List is Empty\n";
	else			   cout << "List is Not Empty\n";
	
	cout << "\nMoves Cursor to the Beggining of the list: \n";
	s1.gotoBeginning();
	
	cout << "\Moves Cursor to the End of the list: \n";
	s1.gotoEnd();
	
	cout << "\n\nGoto Next item of the list\n";
	if( s1.gotoNext() ) cout << "Successfully Moved Cursor\n";
	else cout << "Cursor is At the End of list\n";
	
	cout << "\n\nGoto Prior item of the list\n";
	if( s1.gotoPrior() ) cout << "Successfully Moved Cursor\n";
	else cout << "Cursor is At the Start of list\n";
	
	cout << "\n\nShowing Data items at Cursor: \n";
	s1.getCursor();
	
	cout << "\n\nShowing Structure of List: \n";
	s1.showStructure();
	cout << "\n\n-----The End :) :) \n\n";
	
	return 0;
}
