#include<iostream>
using namespace std;

//O(nlogn)
int intersection2 (int A[], int B[], int C[], int n){
	int count=0, k=0; 
	for ( int i=0; i<n; i++ ){
		int low=0, high=n-1, mid; 
		while(low<=high){
			mid = low + ((high-low)/2);
			if (B[mid]==A[i]){
				C[k] = A[i];
				k++;
				count++;
				break;}
			else if (B[mid]<A[i]) {
				low = mid+1;} 
			else {
				high = mid-1;}	
		}
	}
	return count;
}

int main (){
	int Csize = 0, size=9;
	int a[size] = {1,2,3,4,5,6,7,8,9};
	int b[size] = {1,3,5,7,9,11,13,15,17};
	int c[size];
	int d[size];
	
	cout << "\n---Check 2---\n";
	Csize = intersection2(a,b,d,size);
	cout << "Common Number of Elements in 'a' and 'b' are: " << Csize << endl;
	for ( int i=0; i<Csize; i++)
		cout << d[i] << " ";
	cout << endl;
	
	return 0;
}
