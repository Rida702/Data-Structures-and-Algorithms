#include<iostream>
using namespace std;

//Merge two sorted lists
void merge( int a1[], int a2[], int a3[], int n1, int n2 ){
	int k=0, a=0, b=0,i=0;
	while( true ){
		if(a1[a]==a2[b]) {
			a3[k++]=a1[a++];
			a3[k++]=a2[b++];
		}
		else if(a1[a]<a2[b]) a3[k++]=a1[a++];
		else a3[k++]=a2[b++];
		if(a==n1 || b==n2) break;
	}
	if(a!=n1){
		for( int i=a; i<n1; i++)
			a3[k++] = a1[a++];
	}
	else if(b!=n2){
		for( int i=b; i<n2; i++)
			a3[k++] = a2[b++];
	}	
}

int main(){
//	int arr1[6]={9,20,37,65,92,98}, arr2[4]={26,27,81,82}, arr[10];
//	merge(arr1,arr2,arr,6,4);
//	for( int i=0; i<10; i++)
//		cout << arr[i] << " ";
//	cout << endl;
	
	int arr1[7]={12,23,34,45,56,67,78}, arr2[9]={11,22,33,54,76,79,80,87,90}, arr[16];
	merge(arr1,arr2,arr,7,9);
	for( int i=0; i<16; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
