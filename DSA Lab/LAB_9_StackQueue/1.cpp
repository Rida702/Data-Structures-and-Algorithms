#include<iostream>
#include<stack>
using namespace std;

template <class T>

class Stack{
private:
	//Data members
	T *data; //array of items to be allocated dynamically as per MAX_SIZE
	int top; //top of the stack
	const int MAX_SIZE; //maximum capacity of the stack
public:
	//constructor
	Stack(const int MAX_SIZE = 5);
	//stack manipulation operations
	void push(const T newItem); //push a new item
	void pop(); //pop an item
	void clear(); //clear the stack
	//stack accessor
	T getTop() const; //return item at the top
	//stack status operations
	bool isEmpty() const; //is stack empty?
	bool isFull() const; //is stack full?
	//outputs the data in stack. If the stack is empty, outputs “Empty Stack”.
	void showStructure() const{
		
	}
	//destructor
	~Stack();
};

int main(){
	Stack <int> stack;
	stack.push(5.0);
	stack.push(6.5);
	stack.showStructure();
//	stack.Push(-3.0);
//	stack.Push(-8.0);
//	stack.showStructure();
//	stack.Pop();
//	stack.Pop();
//	stack.showStructure();
	return 0;
}
