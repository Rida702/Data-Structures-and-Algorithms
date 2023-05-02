#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

bool delimitersOk( string str ){
	stack <char> my_stack;
	for( int i=0; i<str.length(); i++ ){
		if( str.at(i)=='(' || str.at(i)=='['){
				my_stack.push(str.at(i));
		}
		if( str.at(i)==')' && my_stack.top()=='(') 	{
			my_stack.pop();
		}
		if( str.at(i)==']' && my_stack.top()=='[') 	{
			my_stack.pop();	
		}
	}
	if(my_stack.empty())	return true;
	else					return false;
}

int main (){
	fstream my_file;
	my_file.open("input.txt", ios::in );
	string line;
	int count =0;
	while(getline(my_file, line, '\n')){
		if(count==0)			continue;
		else{
			if( delimitersOk(line) )cout << "Valid\n";
			else					cout << "Invalid\n";
			count++;
		}		
		
	}
		
	return 0;
}
