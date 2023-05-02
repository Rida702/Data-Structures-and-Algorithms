#include<iostream>
using namespace std;

class Data{
	int array[10];
public:
	Data ( int a[]){
		for ( int i=0; i<10; i++ ){
			array[i] = a[i];
		}
	}
	
	void get_data () {
		for ( int i=0; i<10; i++ )
			cout << array[i] << " ,";
		cout << endl;
	}
	
	void sort ( )
{	int temp = 0;
	for ( int i=0; i<10; i++)
	{
		for ( int j=0; j<9-i; j++)
		{
			if ( array[j]>array[j+1])
			{  
				temp = array[j];   		
				array[j] = array[j+1]; 
				array[j+1] = temp;
			}	
		}
	}
}
};

int main (){
	int arr[10] = { 32,12,54,10,67,46,89,14,23,76};
	Data d1(arr);
	d1.get_data();
	cout << "After Sorting array: \n";       
	d1.sort();                                //32,12,54,10,67,46,89,14,23,76    
	d1.get_data(); 							  //12,32,10,54,46,67,14,23,76,1
	return 0;								  //32,12,54,10,67,46,  ,14,23,76
}
