#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	fstream file;
	int count=0;
	file.open("input.txt",ios::in);
	int a[11]; 
	int x,i;
	cout<<"Roll no: "<<"Scores:"<<endl;
	while (file.good()){
		//reading
		for(i=0;i<11;i++){
			file>>a[i]; 
			cout<<a[i] <<' '; }
		
			int m=a[1];
		//finding highest	
		for(i=1;i<=10;i++){
			if(a[i]>a[m])
				m=i;	
	}
	cout<<"- "<< a[m]<<endl; 
}	
	
	file.close();
}
