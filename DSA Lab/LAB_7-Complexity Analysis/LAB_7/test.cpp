#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
	
	fstream file;
	int count=0, arraysize=10;
	int arr[arraysize];
	string line;
	file.open("test.txt",ios::in);
	
	while (count < arraysize && file >> arr[count]){
        count++;
    }
    
	for(int i=0;i<11;i++){
		cout << arr[i] << '\n'; }
}
