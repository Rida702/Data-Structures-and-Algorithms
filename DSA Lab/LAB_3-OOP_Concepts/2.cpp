#include<iostream>
using namespace std;

class A{
	int a;
public:
	A ( int x1 ){
		a = x1;
	}
	
	void DisplayA( ){
		cout << "A value: " << a << endl;
	}
};

class B : public A{
	int b;
public:
	B ( int x1, int y1 ): A(x1){
		b = x1+y1;
	}
	
	void DisplayB( ){
		cout << "B value: " << b << endl;
	}
	
	
};

class C : public A{
	int c;
public:
	C ( int x1, int y1, int z1 ) : A(x1){
		c = x1+y1+z1;
	}
	
	void DisplayC( ){
		cout << "C value: " << c << endl;
	}
	
};


int main (){
	C c1(1,2,3);
	c1.DisplayC();
	return 0;
}
