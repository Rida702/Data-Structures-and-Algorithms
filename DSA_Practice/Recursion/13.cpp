#include<iostream>
using namespace std;

int Binary_Search( int list[], int low, int high, int key ){
	if(low>high) return -1;
	int mid = low+((high-low)/2);
	//cout << mid << endl;
	if(list[mid]==key)  return mid;
	else if(key<list[mid]) return Binary_Search(list,low,mid-1,key);
	else return Binary_Search(list,mid+1,high,key);
}

int BinarySearch( int list[], int size, int key ){
	Binary_Search( list, 0, size, key );
}

int main(){
	int arr[10]={9,20,26,27,37,65,72,81,82,92}, value=0;
	cout << "{9,20,26,27,37,65,72,81,82,92}" << endl;
	cout << "Enter value: ";
	cin >> value;
	cout << "Index: " << BinarySearch(arr,10,value) << endl;
	//cout << "Index: " << Binary_Search( arr, 0, 10, value ) << endl;
	return 0;
}
