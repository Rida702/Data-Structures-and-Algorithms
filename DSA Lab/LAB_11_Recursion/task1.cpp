#include<iostream>
using namespace std;

double power (double x, int n) {
	if( n==0 ) return 1;
	return x*power(x,n-1);
}

int main(){
	double result=0;
	int num, p;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Enter Power: ";
	cin >> p; 
	result = power(num,p);
	cout << "Result: " <<  result << endl;
	return 0;
}
