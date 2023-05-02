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
	
	void insert ( int id, string name, float cgpa ) {
		Student* temp = new Student(id,name,cgpa,NULL);
		if( head==NULL ) {
			head = temp;
			cursor = temp;	
		}
		else {
			Student* cur = head;
			while(cur->next!=NULL) {
				cur = cur->next;
			}
			cur->next = temp;
			cursor = temp;
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
	
	~StudentList(){
		Student* cur = head;
		while( cur->next!=cursor ){
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
		s1.insert(id,name,cgpa);
	}
	s1.ShowData();
	my_file.close();
	return 0;
}
