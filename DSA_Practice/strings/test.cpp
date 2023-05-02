#include<iostream>
using namespace std;

class String{
public:
	void Show_Duplicate ( string s ) {
		for( int i=0; s[i]!='\0'; i++)
			cout << s[i] << " ";
		cout << endl;
	} 
};

int main (){
	string Input;
	cout << "Enter a String: ";
	cin >> Input;
	cout << "Entered String is: " << Input << endl;
	String s1;
	s1.Show_Duplicate(Input);
	return 0;
}
