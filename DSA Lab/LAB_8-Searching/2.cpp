#include<iostream>
using namespace std;

int findKthSmallest (int A[], int n, int k){
	int temp=0;
	for ( int i=0; i<n-1; i++){
		for ( int j=0; j<n-1-i; j++){	
			if( A[j]>A[j+1] ){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}	
		}
	}
	return A[k-1];
}

int main (){
	int size = 9, k=0, num=0;
	int a[size] = {14,92,13,54,85,61,73,33,9};
	for ( int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "\nEnter number for array of size 9: ";
	cin >> k;
	num = findKthSmallest(a,size,k);
	for ( int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << k << "th Smallest Number from array is: "<< num << endl;
	
	return 0;
}
