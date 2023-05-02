#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class data{
	int arr[30];
	static int count;
public:
//generates random no b/w 1 and 100	
void set_data (){
	srand(time(0));
	for ( int i=0; i<6; i++)
		arr[i] = (rand() % 100) + 1;
	}

void get_data ( ){
	for ( int i=0; i<count; i++)
	if ( i==count-1 )
		cout << arr[i] << endl;
	else cout << arr[i] << " ,";
}

void insert ( int position, int data){
	count++;
	int i=0;
	int temp =0, temp1=0;
	for ( i=6; i>position; i--)
		arr[i] = arr[i-1];
	arr[i] = data;	
	}
};

int data::count = 6;

int main (){
	data d1;
	cout << "Array of 6 elements: \n"; 
	d1.set_data();
	d1.get_data();
	cout << "Insert 56 at 3rd index\n";
	d1.insert(3,56);
	d1.get_data();
	return 0;
}
