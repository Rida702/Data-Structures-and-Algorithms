#include<iostream>
using namespace std;

class StudentDetail {
	string name;
	int rollno;
	int marks;
public:
	StudentDetail ( int r, string n, int m) {
		name = n;
		rollno = r;
		marks = m;
	}
	
	void print ( ){
		cout << rollno << "\t\t";
		cout << name << "\t\t";
		cout << marks << endl;
	}
	
	~StudentDetail () {			}
};

int main (){
	cout << "RollNo\t\tName\t\tMarks\n";
	
	StudentDetail s1(101, "abc", 10);
	s1.print();
	StudentDetail s2(102, "bcd", 15);
	s2.print();
	return 0;
}
