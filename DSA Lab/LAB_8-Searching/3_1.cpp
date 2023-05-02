#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file_1;
	string line;
	file_1.open("input2.txt", ios::in );
	while(getline(file_1, line)) {
		cout << line << endl;
	}
	file_1.close();
	return 0;
}
