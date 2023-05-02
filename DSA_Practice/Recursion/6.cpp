#include<iostream>
using namespace std;

//Sum of first n natural numbers

int sum ( int n ){
	if(n<1) return 0;
	return n+sum(n-1);
}

int main(){
	cout << sum(5) << endl;
	return 0;
}
