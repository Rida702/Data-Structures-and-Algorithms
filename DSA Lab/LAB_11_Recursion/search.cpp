#include<iostream>
using namespace std;

bool search( int a[], int value, int size){
	for( int i=0; i<size; i++)
		if(a[i]==value) return true;
	return false;
}

int main(){
	int value, arr[5] = {1,2,3,4,5};
	cout << "Enter value: ";
	cin >> value;
	if(search(arr,value,5)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
