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

void remove (int id){
	Student* temp = head;
	//No elements in the list
	if(head==NULL) cout << "Linked List is Empty\n" << endl;
	//Delete From Head
	else if(head->id==id){
		head = temp->next;
		temp = NULL;
	}
	//Delete From Cursor 
	else if ( cursor->id==id ){
		while(temp->next!=cursor){
				temp=temp->next;	}
		if( cursor->next==NULL )	{
			temp->next = NULL;
			cursor = head;
		}
		else 						{
			temp->next = cursor->next;
			delete cursor;
			cursor = temp;
		}
	}
	//Delete from anywhere in the middle
	else {
		Student* prev = head;
		while(temp->id!=id){
		prev = temp;
		temp = temp->next;
	}
		prev->next = temp->next;
		temp = NULL;
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
	cout << "\n\t\t--Check 1--\n";
	s1.showStructure();
	my_file.close();
	s1.remove(1);
	cout << "\n\t\t--Check 2--\n";
	s1.showStructure();
	s1.remove(3);
	cout << "\n\t\t--Check 3--\n";
	s1.showStructure();
	s1.remove(10);
	cout << "\n\t\t--Check 4--\n";
	s1.showStructure();
	return 0;
}
