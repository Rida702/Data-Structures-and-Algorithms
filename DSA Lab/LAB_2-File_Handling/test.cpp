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
	
	int count=0, max=0, i;
	string str, word;
	cout << "\nSample output:\n";
	my_file.open("input.txt", ios::in);
	while(getline(my_file, str, '\n')) {
		for( i=0; str[i]!='\0'; i++){
			if( str[i]!=' ' )		word+=str[i];
			else if ( str[i]==' ' || str[i]=='\0' ){
				cout << word << endl;
				word = '\0';
		}
	}
	cout << "i: " << i << endl;
}
	my_file.close();
	return 0;
}
