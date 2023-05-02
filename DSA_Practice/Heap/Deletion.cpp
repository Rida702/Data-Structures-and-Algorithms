#include<iostream>
#include<cmath>
using namespace std;

//Function call is an Overhead you are advised to use these arithmatic functions directly where ever you need them
//MAX heap

int cursize=10;
int A[10]={8,5,4,9,6,1,3,0,7,2};
//left of i
int left ( int i ){
	return (2*i+1);
}

//right of i
int right ( int i ){
	return (2*i+2);
}

//parent of i
int parent( int i ){
	return (i-1)/2;
}

void Max_Heapify ( int *A, int i ) {
	//Starting index at 0, root at 0 location
	//Left Child of i
	int left_i = left(i);
	
	//Right Child of i
	int right_i = right(i);
	
	//Call the ith number the largest
	int largest = i; //Current parent
	
	//Comapring with the left child of i
	if ( left_i<cursize && A[left_i] > A[largest] )
		largest = left_i;
		
	//Comparing the largest of i with left of i
	if( right_i < cursize && A[right_i] > A[largest] )
		largest = right_i;
		
	//Swapping the root
	if( largest!=i ){ //largest will not be equal to i if values at left and right of i were already smaller than i
		int temp;
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		
		//Resursive call to ensure heap for the bottom is not disturbed
		Max_Heapify(A,largest);
	}
}

void build_Heapify ( int A[] ) {
	for( int i=(cursize/2-1); i>=0; i-- )
		Max_Heapify(A,i);
}

int getMax ( ) {
	int max=A[0];
	
	A[0] = A[--cursize];
	Max_Heapify(A,0);
	return max;
}

int main(){
	int n=0, j=0;
	build_Heapify(A);
	for ( int i=0; i<cursize; i++)
		cout << A[i] << " ";
	cout << endl;
	cout << "\n--------------\n";
	cout << "Maximum: " << getMax() << endl; 
	n=0, j=0;
	for ( int i=0; i<cursize; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
