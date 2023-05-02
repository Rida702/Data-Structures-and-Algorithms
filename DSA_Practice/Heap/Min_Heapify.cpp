#include<iostream>
#include<cmath>
using namespace std;

//Function call is an Overhead you are advised to use these arithmatic functions directly where ever you need them
//MAX heap


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

void Min_Heapify ( int *A, int i ){
	//Starting index at 0, root at 0 location
	int cursize=10;
	//Left Child of i
	int left_i = left(i);
	
	//Right Child of i
	int right_i = right(i);
	
	//Call the ith number the smallest
	int smallest = i; //Current parent
	
	//Comapring with the left child of i
	if ( left_i<cursize && A[left_i] < A[smallest] )
		smallest = left_i;
		
	//Comparing the right child of i
	if( right_i < cursize && A[right_i] < A[smallest] )
		smallest = right_i;
		
	//Swapping the root
	if( smallest!=i ){ //largest will not be equal to i if values at left and right of i were already greater than i
		int temp;
		temp = A[smallest];
		A[smallest] = A[i];
		A[i] = temp;
		
		//Resursive call to ensure heap for the bottom is not disturbed
		Min_Heapify(A,smallest);
	}
}

int main(){
	
	int A[10]={8,5,4,9,6,1,3,0,7,2};
	int n=1, j=1;
	cout << "\t" << A[0] << endl;
	while(true){
	int k=j;
	for( int i=j; i<pow(2,n)+k && i<10; i++){
		cout << "\t" << A[i];
		j++;
	}
	n++;
	cout << endl;
	if(j==10) break;
	}
	cout << "\n--------------\n";
	Min_Heapify(A,1);
	n=1, j=1;
	cout << "\t" << A[0] << endl;
	while(true){
	int k=j;
	for( int i=j; i<pow(2,n)+k && i<10; i++){
		cout << "\t" << A[i];
		j++;
	}
	n++;
	cout << endl;
	if(j==10) break;
	}
	return 0;
}
