#include<iostream>
using namespace std;


void merge( int A[], int left, int mid, int right ){
	int n1 = mid-left+1; //+1 for including mid ... size of left sub array
	int n2=right-mid;	//size of right sub array
	
	//Create temporary arrays 
	//Create Dynamically beacause we have to delete them afterwards
	int* L = new int[n1];
	int* R = new int[n2];
	
	//Copy data to temporary array L and R
	for( int i=0; i<n1; i++ )
		L[i]=A[left+i];
		
	for( int i=0; i<n2; i++)
		R[i]=A[mid+1+i];
		
	//Merge the temporary arrays back into original array from left till right
	
	int i=0, j=0, k=left;
	
	while(i<n1 && j<n2 ){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else {
			A[k]=R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remaining elements of Left[l] array if there are any
	while(i<n1){
		A[k]=L[i];
		i++;
		k++;
	}
	
	//Copy the remaining elements of Right[R] array if there are any
	while(j<n2){
		A[k]=R[j];
		j++;
		k++;
	}
	//Free Temporary Arrays 
	delete []L;
	delete []R;
}

void mergeSort( int A[], int left, int right ){
	if(left<right){
		int mid = left+(right-left)/2;
		//Diving the array untill it has atomic items
		//mid is again passed as left or right
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);  //left half 
		merge(A,left,mid,right);  //right half
	}
}

int main(){
	int A[10] = {38,27,43,3,9,55,12,82,10,5};
	mergeSort(A,0,9);
	//Display the array content
	for( int i=0; i<10; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
