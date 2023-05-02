#include<iostream>
using namespace std;

void print1(int n){
	cout << n << " ";
	if(n>1)	print1(n-1);
}

void print2(int n){
	if(n>1)	print2(n-1);
	cout << n << " ";
}

int main(){
	int n=10;
	print1(n);
	cout << "\n------\n";
	print2(n);
	return 0;
}
