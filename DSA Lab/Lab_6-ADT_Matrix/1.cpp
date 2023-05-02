#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Matrix {
private:
	int* arr;
	int rows;
	int cols;
public:
Matrix ( int r, int c){
	if ( r>=0 && c>=0){
		rows = r;
		cols = c;
		arr = new int[rows*cols];
	}
	
}
	
void set_values ( ){
	srand(time(0));
	for ( int i=0; i<rows; i++){
		for ( int j=0; j<cols; j++)
			arr[i*cols + j] = rand() % 100 + 1;
	}
	
}
	
int get(int i, int j){
	if ( i<0 || j<0 )	cout << "Out of matrix boundry Indexes\n";
	else if (  i>rows-1 || j> cols-1 )	cout << "Out of matrix boundry Indexes\n";
	else {
		cout << "Elemnt is: " << arr[i*cols + j] << endl;
	}
} 
	
void set(int i, int j, int v) {
 	if ( i<0 || j<0 )	cout << "Out of matrix boundry Indexes\n";
	else if (  i>rows-1 || j> cols-1 )	cout << "Out of matrix boundry Indexes\n";
	else {
		arr[i*cols + j] = v;
		cout << "Elemnt is: " << arr[i*cols + j] << endl;
	}
}

void print(void){
	for ( int i=0; i<rows; i++){
		for ( int j=0; j<cols; j++)
			cout << arr[i*cols+j] << ' ';
		cout << endl;
	}
} 

void transpose (void){
	int temp;
	for ( int i=0; i<rows; i++){
		for ( int j=i; j<cols; j++){
			temp = arr[i*cols+j];
			arr[i*cols+j] = arr[j*cols+i];
			arr[j*cols+i] = temp;
		}
			
	}
}

void printSubMatrix(int r1, int r2, int c1, int c2){
	for ( int i=r1; i<=r2; i++){
		for ( int j=c1; j<=c2; j++){
			cout << arr[i*cols+j] << " ";
		}
		cout << endl;
	}
}

 void makeEmpty(int n) {
 	for ( int i=0; i<n; i++){
 		for( int j=0; j<cols; j++)
 			arr[i*cols+j] = 0;
	} 
 }
 
void add(Matrix first, Matrix second){
	if ( first.rows == second.rows && first.cols == second.cols ){
		rows = first.rows;
		cols = first.cols;
		for ( int i=0; i<first.rows; i++){
	 		for( int j=0; j<first.cols; j++)
	 			first.arr[i*cols+j] += second.arr[i*cols+j];
	}
	first.print();
}
	else cout << "The Two Given Matrices are Incompatible for addition\n";
}
	
~Matrix ( ){
	delete arr;
}
};

int main (){
	cout << "Taking a matrix of 5x5: \n";
	Matrix m(5,5);
	Matrix m1(5,5);
	Matrix m2(5,5);
	Matrix m3(3,3);
	m.set_values();
	m1.set_values();
	m2.set_values();
	m.print();
	cout << "\n------Finding value 1 (3,3)------\n";
	m.get(3,3);
	cout << "\n------Finding value 2 (6,6)------\n";
	m.get(6,6);
	cout << "\n------Inserting value 1 (3,3)------\n";
	m.set(3,3,5500);
	m.print();
	cout << "\n------Inserting value 2 (6,6)------\n";
	m.set(6,6,5500);
	cout << "\n------Taking transpose------\n";
	m.print();
	cout << "\n-----\n";
	m.transpose();
	m.print();
	cout << "\n------Printing sub matrix------\n";
	m.printSubMatrix(2,4,2,4);
	cout << "\n------Making N rows zero------\n";
	m.print();
	m.makeEmpty(3);
	cout << "\n-----\n";
	m.print();
	cout << "\n------Adding two objects-----\n"; 
	cout << "---1st Matrix: \n";
	m1.print();
	cout << "\n-----\n";
	cout << "---2nd Matrix: \n";
	m2.print();
	cout << "\n-----\n";
	cout << "Addition of the two: \n";
	m.add(m1,m2);
	cout << "\n-----\n";
	
	cout << "Addition of the two: \n";
	m.add(m1,m3);
	cout << "\n-----\n";
	return 0;
}
