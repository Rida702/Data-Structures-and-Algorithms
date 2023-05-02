#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double result=0;
	int num, p;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Enter Power: ";
	cin >> p;
	result = pow(num,p);
	cout << "Result: " << result << endl;
	return 0;
}
