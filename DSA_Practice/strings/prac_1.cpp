#include<iostream>
using namespace std;

class String{
public:
	char Show_Duplicate ( string s ) {
		int count = 0;
		for( int i=0; i<s.length(); i++){
			for( int j=0; j<s.length(); j++){
				if(i==j)	break;
				else {
					if ( s[i] == s[j] )		cout << s[i] << " ";	
				}
	}
	}
} 
};

int main (){
	string Input;
	cout << "Enter a String: ";
	getline(cin, Input);
	cout << "Duplicate values are: ";
	String s1;
	s1.Show_Duplicate(Input);
	return 0;
}
