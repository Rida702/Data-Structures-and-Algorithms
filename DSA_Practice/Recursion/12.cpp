#include<iostream>
using namespace std;

//Linear Search through Recursion 

int linearSearch ( int list[], int size, int key ){
	if( size<0 ) return -1;
	else if( list[size]==key ) return size;
	return linearSearch(list,size-1,key);
}

int main(){
	int arr[10]={20,82,72,26,27,92,81,9,65,37}, value=0;
	cout << "{20,82,72,26,27,92,81,9,65,37}" << endl;
	cout << "Enter value: ";
	cin >> value;
	cout << "Index: " << linearSearch(arr,10,value) << endl;
	return 0;
}
