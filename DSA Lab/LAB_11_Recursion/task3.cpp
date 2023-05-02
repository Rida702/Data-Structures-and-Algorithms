#include<iostream>
using namespace std;

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
	int size;
	cout << "Enter Size: ";
	cin >> size;
	int arr[size];
	for( int i=0; i<size; i++)
		cin >> arr[i];
	reverseSubArray (arr, 0, size-1);	
	for( int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
