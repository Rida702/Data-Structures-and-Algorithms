#include<iostream>
#include<fstream>
using namespace std;

int main (){
	fstream file_1;
	string line;
	int count=0;
	file_1.open("input2.txt", ios::in );
	while(getline(file_1, line, ' '))
		count++;
	cout << "Count of Characters is: " << count << endl;
	int characters=0, arr[count];
	while (file_1.good()){
		cout << "Check 1\n";
	for( int i=0; i<count; i++){
		if(i!=0)	if(arr[0]==arr[i] ) characters++;
		file_1>>arr[i];
		cout << arr[i];
	}
}
	cout << arr[0] << " Occured " << characters << " times" << endl;
	file_1.close();
	return 0;
}
