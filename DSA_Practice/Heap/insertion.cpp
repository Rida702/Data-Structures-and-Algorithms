#include<iostream>
using namespace std;

//Function call is an Overhead you are advised to use these arithmatic functions directly where ever you need them
//MAX heap


const int SIZE=10;
int A[SIZE];
int cursize=0;

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

void insert ( int value ){
	//Check capacity before inserting
	//inserting new item
	A[cursize]=value;
	
	//index of new item
	int new_pos=cursize;
	
	//increment the current size to keep a count of values in the heap
	cursize++;
	while( new_pos!=0 && (A[new_pos] > A[parent(new_pos)] ) ){
		//swap child with it's parent. the child bubbled up
		swap( A[new_pos],A[parent(new_pos)] );
		
		//Note the new index of bubbled up/ Leveled up element
		new_pos = parent(new_pos);
	}
}

int main(){
	
	insert(6);
	insert(8);
	insert(1);
	insert(4);
	insert(7);
	insert(3);
	insert(5);
	insert(0);
	insert(9);
	insert(2);
	
	for ( int i=0; i<SIZE; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
