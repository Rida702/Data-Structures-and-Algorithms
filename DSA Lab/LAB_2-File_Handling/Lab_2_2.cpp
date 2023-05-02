//read from file

#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file_1;
	string line;
	cout << "Roll No.\tName\t\tMarks\n\n";
	file_1.open("student.txt", ios::in );
	while(getline(file_1, line)) {
		cout << line << endl;
	}
	file_1.close();
	return 0;
}
