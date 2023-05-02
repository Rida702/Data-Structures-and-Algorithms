//write in file
#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file;
	string name;
	file.open("test.txt", ios::out | ios::app );
	for( int i=0; i<5; i++) {
	cout << "Enter your name: ";
	cin >> name;
	file << name << "\n";
}
	return 0;
}
