#include<iostream>
using namespace std;

bool check ( string s ){
	int count = 0;
	for( int i=0; i<s.length(); i++){
		if(s[i]>=48 && s[i]<=57 )			count++;
		else							count--;
	}
	if( count==s.length())		return true;
	else						return false;
}
//5. How do you check if a string contains only digits?
int main (){
	string str;
	cout << "Enter a string: ";
	cin >> str;
	if (check(str))			cout << "This String only contains Digits" << endl;
	else					cout << "This String contains alphanumeric words" << endl;
	return 0;
}
