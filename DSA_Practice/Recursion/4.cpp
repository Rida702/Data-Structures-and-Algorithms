#include<iostream>
using namespace std;

double sum ( double a, int n ){
	if(n==0) return 1;
	return 1+sum(a,n-1);
}

double sum1 ( double a, int n ){
	if(n==0) return 1;
	return 1+a*(sum1(a,n-1));
}

int main(){
	cout << sum(2,2) << endl;
	cout << sum1(2,1) << endl;
	return 0;
}
