#include<iostream>
using namespace std;

int arraySum (int A[], int n) {
	if( n>0 )	return A[n-1]+arraySum(A, n-1);
}

int main(){
	int size;
	cin >> size;
	int arr[size];
	for( int i=0; i<size; i++)
		cin >> arr[i];
	int sum=0;
	sum = arraySum(arr,size);
	cout << "Sum of array: " << sum << endl;
	return 0;
}
