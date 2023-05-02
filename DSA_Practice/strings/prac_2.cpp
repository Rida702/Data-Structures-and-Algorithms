#include<iostream>
using namespace std;

bool check_anagrams ( string str1, string str2 ){
	if( str1.length()!=str2.length()) 	return false;
	int count =0;
	for ( int i=0; i<str1.length(); i++){
		for ( int j=0; j<str2.length(); j++)
			if(str1[i]==str2[j]){
				count++;
				str2[j] = -1;
			}	
	}	
	if (count==str1.length())	return true;
	else 						return false;
}

int main (){
	string str1, str2;
	cout << "Enter String 1: ";
	getline(cin, str1);
	cout << "Enter String 2: ";
	getline(cin, str2);
	
	check_anagrams(str1,str2);
	if(check_anagrams(str1,str2)) 			cout << "Strings are Anagrams\n";
	else									cout << "Strings are Not Anagrams\n";
}
