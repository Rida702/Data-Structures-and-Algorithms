#include<iostream>
using namespace std;

bool delimitersOk( const string &expression ){
	stack <char> my_stack;
	for( int i=0; i<expression.size(); i++){
		if( expression.at(i)=='(' || expression.at(i)=='[') my_stack.push(expression.at(i));
		if ( expression.at(i)==')' && my_stack.top()=='(')  my_stack.pop();
		if ( expression.at(i)==']' && my_stack.top()=='[')  my_stack.pop();
	}
	if( my_stack.empty() ) return true;
	else				   return false;
}

int main(){
	string c;
	cin >> c;
	cout << c << endl;
	string str;
	cin >> str;
	if( delimitersOk(str) ) cout << "VALID\n";
	else					cout << "INVALID";
	return 0;
}
