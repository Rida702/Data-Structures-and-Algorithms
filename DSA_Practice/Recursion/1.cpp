#include<iostream>
using namespace std;

void print ( int n ){
	if( n>1 ) print(n-1);
	cout << n << " ";
}

//output of this program will look like this 
//1 2 3 4 5 6 7 8 9 10
//The Program reaches it's Non-Recursive part which is "BASE CASE" of the algorithm 
//then it starts Backtracking towards the calls that generated it
//It's Like Stack LIFO "LAST IN FIRST OUT" principle
//the terminating condition is n==0 so when n becomes zero it backtracks the call which initiated it and that is print(1) 
//A stack is build at the backend not physically but logically
// | print(1)  |
// | print(2)  |
// | print(3)  |
// | print(4)  |
// | print(5)  |
// | print(6)  |
// | print(7)  |
// | print(8)  |
// | print(9)  |
// | print(10) |
int main(){
	int a=10;
	print(a);
	return 0;
}
