#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

bool delimitersOk( string str ){
	stack <char> my_stack;
	for( int i=0; i<str.length(); i++ ){
		if( str.at(i)=='(' || str.at(i)=='[')	my_stack.push(str.at(i));
		if( (str.at(i)==')' && my_stack.top()=='(')) my_stack.pop();
		if( str.at(i)==']' && my_stack.top()=='[') my_stack.pop();	
	}
	if(my_stack.empty())	return true;
	else					return false;
}

int main(){
	fstream my_file;
	string line;
	int count=0;
	my_file.open("input.txt", ios::in );
	int t;
	my_file>>t;
	cout<<"--No: "<<t<<endl;
	while( getline(my_file, line, '\n')){
		if(count==0)	{
			cout << line << endl;
			count++;
		}
		else{
			if(delimitersOk(line)) cout << "Valid\n";
			else				   cout << "Invalid\n";
			count++;
		}
	}
	return 0;
}
