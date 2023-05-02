#include<iostream>
using namespace std;

int factorial ( int num ){
	for ( int i=num-1; i>0; i--)
		num*=i;
	return num;
}

//Formula for permutation
//nPr = n!/(n-r)!		//where n is total and r is the number of letters/items selected from that item at once

int total_permutations( int length ){
	int fact=0, len=0;
	for ( int i=1; i<=length; i++){
		cout << "Length: " << length << endl;
		cout << "len: " << len << endl;
		len = length-i;
		fact += factorial(length)/factorial (len);
	}
	return fact;
}

int main (){
	string str;
	cout << "Enter a String to calculate permutations: ";
	cin >> str;
	int length;
	cout << "Str.length: " << str.length() << endl;
	cout << total_permutations(str.length());
	
	//backward iteration of for loop
	//:(
	//for ( int i=n; i>0; i--){
	//cout << "fact: " << fact << " i: " << i << endl;
	//	}
	return 0;
}
