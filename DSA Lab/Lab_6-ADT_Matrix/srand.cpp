#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main (){
	srand(time(0));
	int a;
	a = rand() % 100 + 1;
	cout << a ;
	return 0;
}
