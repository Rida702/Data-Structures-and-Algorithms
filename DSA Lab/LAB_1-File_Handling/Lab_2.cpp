//read from a file
#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file;
	string name;
	file.open("test.txt", ios::in );
	for ( int i=0; i<5; i++) {
	file >> name;
	cout << "Name: " << name << endl;
}
	return 0;
}
