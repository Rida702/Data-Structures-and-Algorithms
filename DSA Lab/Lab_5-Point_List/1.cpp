#include<iostream>
using namespace std;


struct Point3D {
	float x, y,z;
	Point3D ( ){
		x=-1;
		y=-1;
		z=-1;
	}
	
	Point3D ( float x1, float y1, float z1 ){
		x=x1;
		y=y1;
		z=z1;
	}
};

class PointList {
public:
	Point3D *p1;
	int max_size;
	int cursize;
	int cursor;
public:
	PointList ( ){
		max_size = 0;
		cursize = 0;
	}
	PointList ( int c ){
		cursize = 0;
		cursor = -1;
		max_size = c;
		p1 = new Point3D[c];
	for ( int i=0; i<c; i++){
		p1[i].x = 0;
		p1[i].y = 0;
		p1[i].z = 0;	
	}
}

	bool isEmpty ( ){
		if ( cursor == -1 )	return true;	
		return false;	}
	
	bool isFull ( ){
		if ( cursize != max_size )	return false;
		return true;	}
		
	void insert ( Point3D newPoint ) {
			cursor++;
			cursize++;
			p1[cursor].x = newPoint.x;
			p1[cursor].y = newPoint.y;
			p1[cursor].z = newPoint.z;
	}
	
	void showStructure() {
		if (isEmpty())	cout << "List is Empty\n";
		else {
			for ( int i=0; i<cursize; i++ ){
				cout << "X " << i+1 << ": " << p1[i].x << endl;
				cout << "Y " << i+1 << ": " << p1[i].y << endl;
				cout << "Z " << i+1 << ": " << p1[i].z << endl;
				cout << "\n------\n";
			}
		}
}

	Point3D getCursor() {
	if (  cursor != -1 ){
		cout << "Cursor: " << cursor << endl;
		Point3D *newP  = p1;
		
	}
	else {
		Point3D *p;
		cout << "There are no elements in the list\n";
		cout << "Cursor: " << cursor << endl;
	}
}

	void gotoBeginning (){
		
	}
	
	friend ostream& operator << (ostream &out, const PointList &p){
		out << "x: " << p1[cursor].x << endl;
		out << "y: " << p1[cursor].y << endl;
		out << "z: " << p1[cursor].zs << endl;
	}
	
	~PointList ( ){	delete []p1;	}
};

int main (){
	PointList P(5);
	cout << "\n---CALLING GET CURSOR----\n";
	P.getCursor();
	cout << "\n-------\n";
	
	if ( P.isEmpty() ) 	cout << "--List is Empty\n";
	else				cout << "--List is Not Empty\n";
	
	if ( P.isFull() )	cout << "--List is Full\n";
	else				cout << "--List is Not Full\n";	
	cout << "\n-------\n";
	
	Point3D p1(1,2,3);
	P.insert(p1);
	
	Point3D p2(4,5,6);
	P.insert(p2);
	
	Point3D p3(7,8,9);
	P.insert(p3);
	
	cout << "\n---CALLING GET CURSOR----\n";
	P.getCursor();
	cout << "\n-------\n";
	
	if ( P.isEmpty() ) 	cout << "--List is Empty\n";
	else				cout << "--List is Not Empty\n";
	
	if ( P.isFull() )	cout << "--List is Full\n";
	else				cout << "--List is Not Full\n";
	
	Point3D p4(10,11,12);
	P.insert(p4);
	
	Point3D p5(13,14,15);
	P.insert(p5);
	cout << "\n-------\n";
	
	P.showStructure();
	
	if ( P.isEmpty() ) 	cout << "--List is Empty\n";
	else				cout << "--List is Not Empty\n";
	
	if ( P.isFull() )	cout << "--List is Full\n";
	else				cout << "--List is Not Full\n";
	
	return 0;
}
