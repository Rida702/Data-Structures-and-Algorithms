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

void gotoBeginning () {
	cursor = head;
	cout << "Cursor At Head: " <<  cursor << endl;
}

void gotoEnd () {
	Student* cur = head;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cursor = cur;
	cout << "Cursor At Tail: " <<  cursor << endl;
}

bool gotoNext () {
	cout << "\n---Cursor At Start: " <<  cursor << endl;
	if(cursor->next==NULL) {
		return false;
	}
	else {
		Student* cur = head;
		while (cur!=cursor){
			cur = cur->next;
		}
		cursor = cur->next;
		cout << "\n---Cursor At End: " <<  cursor << endl;
		return true;
	}
	
}

bool gotoPrior () {
	cout << "\nCursor At Start: " << cursor << endl;
	if(cursor==head) {
		return false;
	}
	else {
		Student* cur = head;
		while (cur->next!=cursor){
			cur = cur->next;
		}
		cursor = cur;
		cout << "\n---Cursor At End: " <<  cursor << endl;
		return true;
	}
}

void showStructure () const {
	Student* temp = head;
	cout << "Head: " << head << endl;
	if(head==NULL) cout << "Linked List is Empty\n" << endl;
	while(temp!=NULL){
		cout << "Temp: " << temp << endl;
		temp->studentDetails();
		temp = temp->next;
	}
	//Cursor will be at the end of the list
	cout << "Cursor: " << cursor << endl;
}

Student getCursor () {
	cout << "\n---DATA AT CURSOR: \n";
	cout << "ID: " << cursor->id << endl;
	cout << "Name: " << cursor->name << endl;
	cout << "CGPA: " << cursor->cgpa << endl;
	cout << "-----\n";
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

int main(){
	StudentList s1;
	s1.showStructure();
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
	s1.showStructure();
	cout << "\n\n\t\t---------Showing Data items at Cursor-------------\n";
//	cout << "\n\t\t--Check 1--\n";
//	s1.gotoBeginning();
//	s1.getCursor();
	
//	cout << "\n\t\t--Check 2--\n";
//	s1.gotoEnd();
//	s1.getCursor();
	
//	cout << "\n\t\t--Check 3--\n";
//	s1.gotoPrior();
//	s1.getCursor();

	cout << "\n\t\t--Check 4--\n";
	s1.gotoNext();
	s1.getCursor();
	
	my_file.close();
	return 0;
}
