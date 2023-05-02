//find the two highest scores
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	fstream file;
	int count=0;
	file.open("input.txt",ios::in);
	int a[11]; 
	int x,i,temp;
	cout<<"Roll no: "<<"Scores:"<<endl;
	while (file.good()){
		//reading
		for(i=0;i<11;i++){
			file>>a[i]; 
			cout<<a[i] <<' '; }
		
			int m=a[1];
		//finding highest	
		for(i=1;i<=10;i++){
			for(int j=1;j<11;j++){
				if(a[i]>a[j]){
				
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;}	
	}}
		cout<<" - "<< a[1]<<' '; 
		cout<<" - "<< a[2]<<endl; 
}	
	
	file.close();
}
