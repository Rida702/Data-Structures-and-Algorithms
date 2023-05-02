#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int convert(string s){
	int num = 0;
	for (int i = 0; i < s.length(); i++)
		num = num * 10 + (int(s[i]) - 48);
	cout << num;
	return num;
}

int main (){
	fstream my_file;
	string line;
	cout << "Sample Input:\n";
	my_file.open("input.txt", ios::in);
	while( getline(my_file, line, '\n') ){
		cout << line << endl;
}
	my_file.close();
	
	int max, i, extra, num;
	string str, word;
	cout << "\nSample output:\n";
	my_file.open("input.txt", ios::in);
	while(getline(my_file, str, '\n')) {
		max = 0;
		num = 1;
		for( i=0; str[i]!='\0'; i++){
			if( str[i]!=' ')		word+=str[i];
			else {
				if(num>1){
					extra = int(word);
					//extra = convert(word);
					if ( max<extra)		max=extra;
				}
				cout << word;
				word = '\0';
				num++;
			}
	}
	cout << " " << max << endl;
}
	my_file.close();
	return 0;
}
	
