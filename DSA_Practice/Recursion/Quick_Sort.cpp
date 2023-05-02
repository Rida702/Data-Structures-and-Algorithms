#include<iostream>
using namespace std;

int partition ( int A[], int left, int right ){
	int l=left,r=right;
	int p=left,temp;
	//Choosing first element as pivot
	while(l<r){
		while( A[r]<=A[p] && l<r ) l++; //As long as You're getting elements less than pivot in left half 
		while( A[r]>A[p] ) r--;			//As long as You're getting elements greater than pivot in right half 
		if(l<r) {						//Right r has the correct location of pivot
			temp = A[l];
			A[l] = A[r];
			A[r] = temp;
	}
}
	temp = A[r];
	A[r] = A[p];
	A[p] = temp;
	//Partioning ends here
	return r;
}

void QuickSort ( int A[], int left, int right ){
	if(left<right){
		int pi=partition(A,left,right);
		QuickSort(A,left,pi-1);
		QuickSort(A,pi+1,right);
	}
}

int main(){
	int A[10] = {38,27,43,3,9,55,12,82,10,5};
	QuickSort(A,0,9);
	//Display the array content
	for( int i=0; i<10; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
