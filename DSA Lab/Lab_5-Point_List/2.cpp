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
	
	void show ( ){
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl; 
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
		Point3D newP;
		cout << "Cursor: " << cursor << endl;
		newP  = p1[cursor];
		return newP;
	}
	else {
		Point3D p;
		cout << "There are no elements in the list\n";
		cout << "Cursor: " << cursor << endl;
		return p;
	}
}

	void gotoBeginning (){
		if ( cursor!=-1 )	cursor = 0;	}
		
	void gotoEnd (){
		if ( cursor!=-1 )	cursor = cursize-1;	} 
		
	bool gotoNext (){
	 	if ( cursor != cursize-1 ){
	 		cursor++;
			return false;}
		else return true;		
}

	bool gotoPrior (){
	 	if ( cursor!=0 ) {
	 	cursor--;
		return false;	
}
		else return true;
	}
	
	void clear() {
		for ( int i=0; i<cursize; i++){
			p1[i].x = NULL;
			p1[i].y = NULL;
			p1[i].z = NULL;
			cursize--;
			cursor=-1;
		}
	}
	
	bool replace(Point3D newPoint) {
		
		if ( cursor!=-1 ){
			p1[cursor].x = newPoint.x; 
			p1[cursor].y = newPoint.y; 
			p1[cursor].z = newPoint.z; 
			cout << "Cursor: " << cursor << endl;
			return true;
		}
		
		else return false;
	}
	
	void remove() {
		if ( cursor!=-1 ){
			p1[cursor].x = p1[cursize-1].x; 
			p1[cursor].y = p1[cursize-1].y; 
			p1[cursor].z = p1[cursize-1].z; 
			cout << "Cursor: " << cursor << endl;
			cursize--;
		}
	}
	
	~PointList ( ){	delete []p1;	}
};

int main (){
	PointList P(5);
	cout << "\n---CALLING GET CURSOR----\n";
	Point3D obj1 = P.getCursor();
	obj1.show();
	
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
	obj1 = P.getCursor();
	obj1.show();
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
	
	cout << "\n---Go to Begginning----\n";
	cout << "Cursor: " << P.cursor << endl;
	P.gotoBeginning();
	cout << "Cursor: " << P.cursor << endl;
	cout << "\n-------\n";
	
	cout << "\n---Go to End----\n";
	cout << "Cursor: " << P.cursor << endl;
	P.gotoEnd();
	cout << "Cursor: " << P.cursor << endl;
	cout << "\n-------\n";
	
	cout << "\n---Go to Next----\n";
	cout << "Cursor: " << P.cursor << endl;
	if( P.gotoNext() )		cout << "Cursor is at the end of list already\n";
	else 					cout << "Cursor shifted at the end of list\n";
	cout << "Cursor: " << P.cursor << endl;
	cout << "\n-------\n";
	
	cout << "\n---Go to Prior----\n";
	cout << "Cursor: " << P.cursor << endl;
	if( P.gotoPrior() )		cout << "Cursor is at the start of list already\n";
	else 					cout << "Cursor shifted at the previous item of list\n";
	cout << "Cursor: " << P.cursor << endl;
	cout << "\n-------\n";
	
//	cout << "\n---Removing List---\n";
//	cout << "Current size: " << P.cursize << endl;
//	P.clear();
//	cout << "Current size: " << P.cursize << endl;
//	P.showStructure();
	
	cout << "\n---Replacing Elements in the List---\n";
	Point3D p6(44,55,66);
	if ( P.replace(p6) )		cout << "Element Replaced Successfully\n";
	else						cout << "List is Empty So element cannot be replaced\n";
	P.showStructure();
	
	cout << "\n---Removing Elements in the List---\n";
	P.remove();
	P.showStructure();
	return 0;
}
