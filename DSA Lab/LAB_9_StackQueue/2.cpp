#include<iostream>
using namespace std;

template <class T>
class Queue{
public:
//constructor
Queue(const int MAX_SIZE = 5);
//destructor
~Queue();
//queue manipulation operations
void enQueue(const T newItem); //add an element to the rear of queue
void deQueue(); //delete element at the front of queue
void clear(); //clear the queue
//queue accessors
T getFront() const; //return element at the front
T getRear() const; //return element at the rear
//queue status operations
bool isEmpty() const; //is queue empty?
bool isFull() const; //is queue full?
//outputs the data in queue. If the queue is empty, outputs “Empty Queue”.
void showStructure() const;
private:
//data members
T *data; //array of items to be allocated dynamically as per MAX_SIZE
int front; //front index
int rear; //rear index
const int MAX_SIZE; //size of queue
};

int main(){
	return 0;
}
