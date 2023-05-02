//write in file
#include<iostream>
#include<fstream>
using namespace std;

int main ( ){
	fstream file1;
	int marks, rollno;
	string name;
	file1.open("my_file.txt", ios::out | ios::app );
	for ( int i=0; i<5; i++){
		cout << "Enter your name: ";
		cin >> name;
		file1 << name << ", ";
		cout << "Enter your Roll no: ";
		cin >> rollno;
		file1 << rollno << ", ";
		cout << "Enter your Marks: ";
		cin >> marks;
		file1 << marks << endl;
	}
	
	file1.close();
	
	string line;
	file1.open("my_file.txt", ios::in );
	while(getline(file1, line, '\n')) {
		cout << line << endl;
	}
}
