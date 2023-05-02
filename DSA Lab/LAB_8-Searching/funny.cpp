#include<iostream>
#include <stack>
using namespace std;

//0 is notPrime
//1 is Prime

bool isPrime( int number ){
	int count=0;
	if ( number>1){
	for( int i=1; i<=number; i++ ){
		if( number%i==0 ) count++;
		if ( count>2 && i>number) {
			return false;
			break;
		}
	}
	if ( count>2 )		return false;
	else 				return true;
}
	else return false;
}

//0 is Not Perfect
//1 is Perfect
bool isPerfect ( int number ){
	if ( number>0 ){
	int array[number/2], k=0, num=0;
	for ( int i=1; i<number; i++)
		if( number%i==0 )	array[k++] = i;
		
	for (  int i=0; i<k; i++)
		num+=array[i];
	
	if ( num==number)		return true;
	else 					return false;
	}
	else return false;
}


bool Test1 ( stack <int> s ) {
	int num;
	while ( !s.empty()){
		num+=s.top();
		s.pop();
	}
	cout << "Test1 num-1: " << num-1 << endl;
	if ( isPrime(num-1) )		return true;
	else 					return false;
}

bool Test2 ( stack <int> s, int c ){
	int mid = c/2, i=0;		//mid=2
	int firsthalf=0, secondhalf=0, result; 
	if ( c%2!=0 ){
		while( !s.empty() ){
		if ( i<mid ) 	{
			firsthalf+=s.top();
			s.pop();
			i++;}
		else if ( i>mid && i<=c ) {
			secondhalf+=s.top();
			s.pop();
			i++;}
		else {
			s.pop();
			i++;}
		}
	}
	
	else {
		while( !s.empty() ){
		if ( i<mid ) 	{
			firsthalf+=s.top();
			s.pop();
			i++;}
		else if ( i>=mid && i<c ){
			secondhalf+=s.top();
			s.pop();
			i++;}
	}
	
	cout << "First Half: " << firsthalf << endl;
	cout << "Second Half: " << secondhalf << endl;
	result = firsthalf-secondhalf;
	cout << "result: " << result << endl;
	if ( result<0 )	result*=-1;
	if ( isPerfect(result))		return true;
	else						return false;
}

}

int main () {
//	stack <int> stack, stack1;
	int input, size;
	cin >> size;
	int array[size];
	for ( int i=0; i<size; i++){
		stack <int> stack, stack1;
		int intcount=0;
		cin >> input;
		while( input!=0){
		stack.push(input%10);
		stack1.push(input%10);
		input = input/10;
		intcount++;
	}
	
	cout << "Test 1: " << Test1(stack) << endl;
	cout << "---\n";
	cout << "Test 2: " << Test2(stack1,intcount) << endl;
	cout << "---\n";
	if ( Test1(stack) && Test2(stack1,intcount) )		array[i]=1;
	else												array[i]=0;
	while ( !stack.empty() ){
		stack.pop();
	}
	while ( !stack1.empty()){
		stack1.pop();
	}
	}
	
	for ( int i=0; i<size; i++){
		cout << "Case #" << i+1 << ": ";
		if (array[i]==1)		cout << "Funny" << endl;
		else 					cout << "Serious" << endl;
	}
	return 0;
}
