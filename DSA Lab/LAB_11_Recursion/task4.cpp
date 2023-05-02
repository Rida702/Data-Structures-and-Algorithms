#include<iostream>
using namespace std;

bool search( int a[], int value, int size){
	for( int i=0; i<size; i++)
		if(a[i]==value) return true;
	return false;
}

bool checkSum (int A[], int start, int end, int k){
	int key;
	if(start<=end){
		key = k - A[start];
		if(  search(A,key,end) ) return true;
		else checkSum (A, start++, end, k);
	}
	return false;
}

int main(){
	int s,k;
	char ch;
	cout << "Enter the size of array: ";
	cin >> s;
	int x[s];
	cout << "Enter the " << s <<" elements of the array: ";
	for( int i=0; i<s; i++)
		cin >> x[i];
	do{
		cout << "Enter k: ";
		cin >> k;
		if(checkSum(x,0,s-1,k)) cout << k << " can be obtained by adding two elements of the array." << endl;
		else	cout << k << " can NOT be obtained by adding two elements of the array." << endl;
		cout << "More (y/n)?: ";
		cin >> ch;
	}while(ch=='y');
	return 0;
}
