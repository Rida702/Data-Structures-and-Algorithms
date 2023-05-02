//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//#include <ctime>
#include "bits/stdc++.h"
using namespace std;
class que{
stack <int> s1;
stack <int> s2;
public:
int push(int x){
	cout<<"PUSH: "<<x<<endl;
	s1.push(x);
}
int pop(){
	if(s1.empty() && s2.empty()){
		cout<<"STACK IS EMPTY "<<endl;
		
	} 
	if(s2.empty()){
		while(!s1.empty()){
				s2.push(s1.top());
			s1.pop();
		}	
	}
//	if(s1.empty())
	int a=s2.top();
	cout<<"Pop: ";
	s2.pop();
	return a;	
	cout<<endl;
}
//		bool empty(){
//			if(s1.empty() && s2.empty()){
//				return true ;
//			}
//			return false;
//		}
};
int main(){
que q;
q.push(1);
q.push(2);
q.push(3);
cout<<q.pop()<<endl;
q.push(4);
cout<<q.pop()<<endl;
cout<<q.pop()<<endl;
cout<<q.pop()<<endl;
//when stack is empty
cout<<q.pop()<<endl;

}
