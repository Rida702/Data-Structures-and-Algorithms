#include<iostream>
using namespace std;

//write a recursive function that return power of a number
int power( int a,int n ){
	if(n<1) return 1;
	return a*power(a,n-1);
}

int main(){
	int n1,n2;
	cout << "Enter Number: ";
	cin >> n1;
	cout << "Enter it's power: ";
	cin >> n2;
	cout << "Result: " << power(n1,n2) << endl;
	return 0;
}
