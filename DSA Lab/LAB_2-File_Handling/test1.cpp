#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream my_file;
	string line;
	cout << "Sample Input:\n";
	my_file.open("input.txt", ios::in);
	while( getline(my_file, line, '\n') ){
		cout << line << endl;
}
	my_file.close();
	
	
	cout << "\nSample output:\n";
	int count=0, max=0;
	string str;
	my_file.open("input.txt", ios::in);
	while(getline(my_file, str)) {
		cout << str << endl;
	}
	my_file.close();
	
	
	cout << "\nSample output:\n";
	my_file.open("input.txt", ios::in);
	while(getline(my_file, str, ' ')) {
		cout << str << endl;
	}
	my_file.close();
	
	return 0;
}
