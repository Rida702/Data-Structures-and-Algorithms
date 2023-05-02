#include<iostream>
using namespace std;

int sum1(int n){
	if(n==0) return 0;
	return sum1(n-1)+n;
}

int sum2(int n){
	if(n==0) return 0;
	return sum2(n-1)+(n*n);
}

int sum3(int n){
	if(n==0) return 0;
	return sum3(n-1);
}

int sum4(int n){
	if(n==0) return 0;
	return n*n;
}


int main(){
	cout << "SUM 1: " << sum1(3) << endl;
	cout << "SUM 2: " << sum2(3) << endl;
	cout << "SUM 3: " << sum3(3) << endl;
	cout << "SUM 4: " << sum4(3) << endl;
	return 0;
}
