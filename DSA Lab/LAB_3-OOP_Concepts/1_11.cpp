#include<iostream>
using namespace std;

class StudentDetail {
	string name;
	int rollno;
	int marks;
public:
//y5exhyi	
	StudentDetail ( ) {		}
	
	StudentDetail ( int r, string n, int m) {
		this->name = n;
		this->rollno = r;
		this->marks = m;
	}
	
	void print ( ){
		cout << this->name << "\t\t";
		cout << this->rollno << "\t\t";
		cout << this->marks << endl;
	}
	
	void input ( ){
		cout << "Enter Your name: ";
		cin >> name;
		cout << "Enter Your RollNo: ";
		cin >> rollno;
		cout << "Enter Your Marks: ";
		cin >> marks;
	}
	
	~StudentDetail () {			}
};

int main (){
	int n, roll, marks;
	string stu_name;
	cout << "Enter no of students you want to display data of: ";
	cin >> n;
	StudentDetail s1[n];
	
	for ( int i=0; i<n; i++){
		s1[i].input();
	}
	cout << "RollNo\t\tName\t\tMarks\n";
	for ( int i=0; i<n; i++){
		s1[i].print();
	}
	return 0;
}
