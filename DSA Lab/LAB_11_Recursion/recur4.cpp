#include<iostream>
using namespace std;

bool search( int a[], int value, int size, int start){
	for( int i=0; i<size; i++)
		if(i==start) continue;
		else if(a[i]==value) return true;
	return false;
}

bool checkSum (int A[], int start, int end, int k){
	int key, flag=0;
	if(start<=end){
		key = k - A[start++];
		cout << A[start] << endl << k << endl << key << endl;
		if(  search(A,key,end,start-1) ) {
			flag=1;
			return true;
		}
		else checkSum (A, start, end, k);
	}
	if( flag==0 ) return false;
	else return true;
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
