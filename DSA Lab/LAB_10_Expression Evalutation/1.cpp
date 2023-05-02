#include<iostream>
#include<stack>
using namespace std;

bool delimitersOk( string str ){
	stack <char> my_stack;
	for( int i=0; i<str.length(); i++ ){
		if( str.at(i)=='(' || str.at(i)=='[')
				my_stack.push(str.at(i));
		if( str.at(i)==')' && my_stack.top()=='(')
			my_stack.pop();
		if( str.at(i)==']' && my_stack.top()=='[')
			my_stack.pop();	
	}
	if(my_stack.empty())	return true;
	else					return false;
}

int main (){
	string str;
	int t;
	cin >> t;
	for( int run=0; run<t; run++){
		cin >> str;
		if( delimitersOk(str) ) cout << "Valid\n";
		else					cout << "Invalid\n";
	}
		
	return 0;
}
