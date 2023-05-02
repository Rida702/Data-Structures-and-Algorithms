#include<iostream>
using namespace std;

void check_duplicates ( string s ){
for ( int i=0; i<s.length(); i++) {
	for ( int j=0; j<s.length(); j++) {
		if(i!=j) {	
			if ( s[i]==s[j] ) {
				cout << "Found Duplicate of: " << s[j] << endl;
				s[j] = -1;
			}
		}
	}
 }
}

//6. How do you find duplicate characters in a given string?
int main ( ) {
	string str;
	cout << "Enter a String: ";
	getline(cin,str);
	check_duplicates (str);
	return 0;
}
