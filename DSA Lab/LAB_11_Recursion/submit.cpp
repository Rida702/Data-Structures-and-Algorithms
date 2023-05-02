#include<iostream>
using namespace std;

double power (double x, int n) {
	if( n==0 ) return 1;
	return x*power(x,n-1);
}

int arraySum (int A[], int n) {
	if( n>0 )	return A[n-1]+arraySum(A, n-1);
}

void reverseSubArray (int A[], int start, int end){
	int temp;
	if( start<end ){
		temp = A[start];
		A[start] = A[end];
		A[end] = temp;
		start++;
		end--;
		return reverseSubArray(A,start,end);
	}	
}

int main(){
	//Task - 1
	cout << "\t\t*-*-* Task-1 *-*-*-*" << endl;
	double result=0;
	int num, p;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Enter Power: ";
	cin >> p; 
	result = power(num,p);
	cout << "Result: " <<  result << endl;
	
	
	//Task - 2
	cout << "\t\t*-*-* Task-2 *-*-*-*" << endl;
	int size, sum=0;
	cout << "Enter Size: ";
	cin >> size;
	int arr[size];
	for( int i=0; i<size; i++)
		cin >> arr[i];
	sum = arraySum(arr,4);
	cout << "Sum of array: " << sum << endl;
	
	//Task - 3
	cout << "\t\t*-*-* Task-3 *-*-*-*" << endl;
	int size1;
	cout << "Enter Size: ";
	cin >> size1;
	int arr1[size1];
	for( int i=0; i<size1; i++)
		cin >> arr1[i];
	reverseSubArray (arr1, 0, size1-1);	
	for( int i=0; i<size1; i++)
		cout << arr1[i] << " ";
	cout << endl;
	return 0;
}
