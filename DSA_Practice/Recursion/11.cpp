#include<iostream>
using namespace std;

int sum_array(int a[], int n){
	if(n<0) return 0;
	return a[n-1]+sum_array(a,n-1);
}

int main(){
	int arr[10]={20,82,72,26,27,92,81,9,65,37}, sum=0;
	for( int i=0; i<10; i++)
		sum+=arr[i];
	cout << "Sum 1: " << sum << endl;
	cout << "Sum 2: " << sum_array(arr,10) << endl;
	return 0;
}
