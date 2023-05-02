#include<iostream>
using namespace std;

void count ( string s ){
	int consonant=0, vowel=0;
	for( int i=0; i<s.length(); i++){
		if ( s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || 
			 s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
			 	vowel++;
		else 	consonant++;	
	}
	cout << "Number of Vowels: " << vowel << endl;
	cout << "Number of consonants: " << consonant << endl;
}

int main (){
	string str;
	cout << "Enter a String: ";
	getline(cin,str);
	count(str);
	return 0;
}
