#include<iostream>
using namespace std;

//Write a function that returns the sum of the squares of the first n positive integers
//generic formula = [n(n+1)(2n+1)]/6

int sum_of_squares( int n ){
	if(n<1) return 0;
	return (n*n)+sum_of_squares(n-1);
}

int main(){
	cout << sum_of_squares(5) << endl;
	return 0;
}
