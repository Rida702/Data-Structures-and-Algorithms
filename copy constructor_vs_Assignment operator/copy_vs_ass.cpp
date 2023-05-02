#include<iostream>
using namespace std;

//Test t3 = t1; 		//calls Copy Const
//t2 = t1				//calls Assignment operator

//If u dont define both of these or any one of these compiler will CALL the default version
class Test {
	int data;
public:
	Test ( int d) : data(d){		}
	Test ( const Test &t ){	 
		this->data=t.data;
		cout << "Copy Const\n"; 
	}
	Test operator = ( const Test &t ) {
		this->data=t.data;
		cout << "Assignment Operator\n";  
	}
	void show () {	cout << "Data: " << data << endl; }
};

int main (){
	Test t1(4), t2(5);
	t1.show();
	t2.show();
	cout << "-------------\n";
	Test t3 = t1;
	t1.show();
	t3.show();
	cout << "-------------\n";
	t1 = t2;
	t1.show();
	t2.show();
	cout << "-------------\n";
	return 0;
}
