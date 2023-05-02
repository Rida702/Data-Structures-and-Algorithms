#include<iostream>
#include<stack>
using namespace std;

template <class T> 
class Stack{
private:
	T *data; 
	int top; 
	int MAX_SIZE;
public:
	Stack(){
	    MAX_SIZE=5;
		data = new T[MAX_SIZE];
		top=-1;
	}
	void push(T newItem){
		top++;
		data[top] = newItem;
	} 
	void pop(){
		top--;
	}
	void clear(){
		top=-1;
	} 
	T getTop() const{
		return data[top];
	} 
	bool isEmpty() const{
		if(top==-1) return true;
		else		return false;
	}
	bool isFull() const{
		if(top==MAX_SIZE) return true;
		else			  return false;
	} 
	void showStructure() const{
		if( top==-1) cout << "Stack is Empty\n";
		else{
			for( int i=top; i>=0; i--){
			if( i==top ) cout << "top -->\t\t" << data[i] << endl; 
			else cout << "\t\t" << data[i] << endl; }	
		cout << "\t------------------\n";
	}
}
	~Stack(){
		delete []data;
	}
};

int main(){
	Stack<float> stack;
	stack.push(5.66);
	stack.push(6.55);
	stack.showStructure();
	stack.push(-3.0);
	stack.push(-8.0);
	stack.showStructure();
	stack.pop();
	stack.pop();
	stack.showStructure();
	float a;
	a= stack.getTop();
	cout << "Top value is: " << a << endl;
	if( stack.isEmpty() )	cout << "Stack is Empty\n";
	else				cout << "Stack is not Empty\n";
	if( stack.isFull() )	cout << "Stack is Full\n";
	else				cout << "Stack is not Full\n";
	return 0;
}
