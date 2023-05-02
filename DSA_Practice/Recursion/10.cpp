#include<iostream>
using namespace std;

//write a recursive function to print an integer array

int print_array( int a[], int n ){
	if(n==1) return a[n-1];
	cout << a[n-1] << " ";
	return print_array(a,n-1);
}

int show_data( int a[], int n ){
	static int i=0;
	if(i==n-1 ) return a[i];  
	cout << a[i++] << " ";
	return show_data(a,n);
}

int main(){
	int arr[10]={20,82,72,26,27,92,81,9,65,37};
	cout << print_array(arr,10) << endl;
		cout << "------\n";
	cout << show_data(arr,10) << endl;
	return 0;
}
