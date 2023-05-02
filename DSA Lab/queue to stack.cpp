#include <bits/stdc++.h>
using namespace std;

class queue_to_stack{
queue <int> q1;
queue <int> q2;
public:
	int push(int x){
		//cout<<"PUSH: "<<x<<endl;
		q1.push(x);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		swap(q1,q2);
	}
	
		
int pop(){
	int a;
	if (q2.empty())		
		cout<<"EMPTY "; return -1;
	else {	a=q2.front();
		q2.pop();
		return a; }
}
			
};
		
		
int main(){
	
	queue_to_stack q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.pop() <<endl;
	q.push(4);
	cout << q.pop() << endl;
	cout << q.pop() <<endl;
	cout << q.pop() <<endl;
	//when stack is empty
	cout << q.pop() <<endl;

}			
