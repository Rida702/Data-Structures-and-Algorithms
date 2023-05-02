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

void search (float cgpa) const {
	int flag = 0;
	Student* cur = head;
	while(cur!=NULL){
		if(cur->cgpa==cgpa) {
			cur->studentDetails();
			flag=1;
		}
		cur = cur->next;
		
	}
	if( flag==0 ) cout << "No Records Found\n";
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
	cout << "\n\t\t--Check 1--\n";
	s1.search(3.22);
	cout << "\n\t\t--Check 2--\n";
	s1.search(4.65);
	cout << "\n\t\t--Check 3--\n";
	s1.search(2.15);
	my_file.close();
	return 0;
}
