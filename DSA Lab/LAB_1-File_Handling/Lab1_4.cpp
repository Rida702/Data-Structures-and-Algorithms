//count characters, white spaces , words and lines in file
#include<iostream>
#include<fstream>
using namespace std;

int main ( ){
	fstream file1;
	string line;
	int line_count=0, word_count=0, char_count=0, space_count=0;
	//line count code
	file1.open("my_file.txt", ios::in );
	while(getline(file1, line, '\n')) {
		line_count++;
		cout << line << endl;
	}
	cout << "\n\n--Total Lines are: " << line_count << endl;
	file1.close();
	//word count code
	file1.open("my_file.txt", ios::in );
	while(getline(file1, line, ',')) {
		word_count++;
	}
	cout << "--Total words are: " << word_count << endl;
	file1.close();
	
	
	//character count code
	file1.open("my_file.txt", ios::in );
	char ch;
    int i;
    while(file1)
    {
        file1.get(ch);
        i=ch;
		if (ch== ' ')
            space_count++;
        else if ( ch==',')		continue;
        else if ( (i >= 64 && i <= 90 ) || (i >= 97 && i <= 122 ) || i>=48 && i<=57 )
			char_count++;
    }
    cout << "--Total Characters are: "<< char_count << endl;
    cout << "--Total white Space are: "<< space_count << endl;
	file1.close();
	return 0;
}
