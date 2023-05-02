//write inside file
#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file_1;
	string first_name, last_name;
	int rollNo, marks;
	file_1.open( "student.txt", ios::out | ios::app );
	while(rollNo!=-999){
		cout << "Enter Roll Number: ";
		cin >> rollNo;
		if (rollNo==-999)		break;
		file_1 << rollNo << "\t";
		
		cout << "Enter First Name: ";
		getline(cin >> ws, first_name);
		file_1 << first_name << " ";
		
		cout << "Enter Last Name: ";
		getline(cin >> ws, last_name);
		file_1 << last_name << "\t\t";
		
		cout << "Enter Marks: ";
		cin >> marks;
		file_1 << marks << endl;
	}
	file_1.close();
	return 0;
}
