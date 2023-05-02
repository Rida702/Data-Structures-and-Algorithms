#include<iostream>
using namespace std;

template <class T>
class Queue{
private:
	T *data;
	int front; 
	int rear; 
	int MAX_SIZE;
public:
	Queue () {
		MAX_SIZE=5;
		data = new T[MAX_SIZE];
		front=-1;
		rear=-1;
	}
	void enQueue(const T newItem){
		rear=(rear+1)%MAX_SIZE;
		data[rear] = newItem;
		if(rear==0 && front==-1) front=rear;
	}
	void deQueue(){
		front=(front+1)%MAX_SIZE;
	}
	void clear(){
		front=rear=-1;
	}
	T getFront() const{
		return data[front];
	}
	T getRear() const{
		return data[rear];
	}
	bool isEmpty() const{
		if(front==-1) return true;
		else		  return false;		
	}
	bool isFull() const{
		if(rear==MAX_SIZE)  return true;
		else		  		return false;	
	}
	void showStructure() const{
		
		for( int i=front; i<=rear; i++){
			if(i==front) cout << "Front--->" << "\t " << data[i] << endl;
			else if(i==rear)	 cout << "\t\t " << data[i] << "\t\t<---Rear" << endl;
			else cout << "\t\t " << data[i] << endl;
		}
		
	}
	~Queue(){
		delete []data;
	}
};

int main(){
	Queue<float>queue;
	queue.enQueue(5.0);
	queue.enQueue(6.5); 
	queue.showStructure();
	queue.enQueue(-3.0); 
	queue.enQueue(-8.0);
	queue.showStructure();
	queue.deQueue();
	queue.deQueue();
	queue.showStructure();
	float a;
	a = queue.getFront();
	cout << "Queue Front is: " << a << endl;
	a = queue.getRear();
	cout << "Queue Rear is: " << a << endl;
	if(queue.isEmpty())	cout << "Queue is Empty" << endl;
	else				cout << "Queue is Not Empty" << endl;
	if(queue.isFull()) cout << "Queue is Full" << endl;
	else			   cout << "Queue is Not Full" << endl;
	return 0;
}
