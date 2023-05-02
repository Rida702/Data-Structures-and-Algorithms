#include<iostream>
using namespace std;

class Collection{
	int *data;
	int size;
	int count;
public:
	
Collection ( ){
	data = NULL;
	size = -1;
}	
Collection ( int s ) : size(s){
	count=0;
	data = new int[size];
}

Collection ( int *arr, int s  ) : size(s) {
	count=0;
	data = new int[size];
	for ( int i=0; i<size; i++)
		data[i] = arr[i];
}
	
// copies data of the &c parameter	
Collection ( const Collection &c ) {
	cout << "Copy Const called.\n";
	size = c.size;
	data = new int[size];
	for ( int i=0; i<size; i++)
		data[i] = c.data[i];
}

Collection& operator = ( const Collection &c ) {
	cout << "Assignment operator called.\n";
	size = c.size;
	data = new int[size];
	for ( int i=0; i<size; i++)
		data[i] = c.data[i];
	return *this;
}

Collection& operator + ( const Collection &c ){
	cout << "+operator called\n";
	//Collection Newc;
	if ( size == c.size ){
		//Newc.data = new int[size];
		for ( int i=0; i<size; i++)
			data[i] = data[i]+c.data[i];
	}
	else cout << "Not Possible\n";
	return *this;
}
	
bool operator == ( const Collection &c  ){
	int check =0;
	for ( int i=0; i<size; i++ ){
		if( data[i] == c.data[i] ) check++;
	}
	cout << "size: " << size << endl;
	cout << "c.size: " << c.size << endl;
	cout << "check: " << check << endl;
	return ( size == c.size && check==size-1 );
}	
	
int getSize (){
	cout << "Enter the size of data collection: ";
	cin >> size;
	return size;
}
	
int* getCollection ( int s ){
	for ( int i=0; i<s; i++){
		cout << "Input " << i+1 << " Element of collection: ";
		cin >> data[i];
	}
	return data;
}
	
int* insertElement ( int value, int index ){
int temp, temp1;
if( index<size){
size++;
for( int i=index; i<size; i++){
	if(index==i){
		temp=data[i];
		data[i] = value;
	}
	else {
		temp1 = data[i];
		data[i] = temp;
		temp = temp1;
	}
}
}
else cout << "Index exceeds the size of the array\n";
}

//Find an element
void findElement ( int element ){
	int check=0;
	for ( int i=0; i<size; i++){
		if ( data[i] == element ){
			cout << "Element fount at " << i+1 << " position\n";
			check++; }
	}
	if ( check==0 ) cout << "Element Not fount\n";
}

void printCollection ( ){
	for ( int i=0; i<size; i++ )
		cout << data[i] << " ";
	cout << endl;
}

~Collection (){
	//cout << "Destructor\n";
	delete data;
}

friend ostream& operator << ( ostream &out, const Collection &c ){
	for ( int i=0; i<c.size; i++)
		out << c.data[i] << " ,";
	cout << endl;
}
};

int main ( ){
	//Create an object, input size and input elements for that size array and show it
	Collection c1(5);
	int size;
	int *array1;
	size = c1.getSize();
	array1 = new int[size];
	array1 = c1.getCollection(size);
	cout << "\n-----------" << endl;
	cout << "Elements of C1: ";
	c1.printCollection();
	
	//Create an object and initialize size and array with paramerterized constructor and print them
	cout << "\n-----------" << endl;
	int array[6] = { 11,12,13,14,15,16};
	Collection c2(array, 6);
	cout << "Elements of C2: ";
	c2.printCollection();
	
	//Create a new object and copy data in it using copy constructor and print it
	cout << "\n--Copy C3 = C1--\n";
	Collection c3 = c1;
	cout << "Elements of C3: ";
	c3.printCollection();
	
	//Input an index and value to insert in the collection
	int index, value;
	cout <<"C3:Enter an index and a value which u want to insert in collection: ";
	cin >> index >> value;
	c3.insertElement(value,index);
	c3.printCollection();
	
	//Input a value from user and see if it exists in collection or not
	cout <<"C1:Enter the value you want to searh in collection: ";
	cin >> value;
	c1.findElement(value);
	
	//Assignment operator
	
	cout << "\n--Copy C3 = C2--\n";
	c3 = c2;
	cout << "Elements of C2: ";
	c2.printCollection();
	cout << "Elements of C3: ";
	c3.printCollection();

	cout << "\n--Plus: C1+C2 --\n";
	c3 = c1+c2;
	cout << "C1+C2: " << c3 << endl;
	
	cout << "\n--Plus: C1+C2 --\n";
	cout << "C1+C2: " << c1+c2 << endl;
	
	cout << "Elements of C1: ";
	c1.printCollection();
	cout << "Elements of C2: ";
	c2.printCollection();
	cout << "Elements of C3: ";
	c3.printCollection();
	if ( c1==c2 ) 			cout << "C1 and C2 are equal\n";
	else					cout << "C1 and C2 are not equal\n";
	
	if ( c1==c3 ) 			cout << "C1 and C3 are equal\n";
	else					cout << "C1 and C3 are not equal\n";

}
