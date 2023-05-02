#include<iostream>
#include<fstream>
using namespace std;

class Student
{
friend class StudentBST;
private:
int stdId; //student identifier (unique)
string name; //student name
float fee; //student fee
Student* left; //left subtree of a node
Student* right; //right subtree of a node
};
class StudentBST
{
private:
Student* root; //root of the tree
public:
StudentBST(); //constructor
~StudentBST(); //destructor
};


int main(){
	int id; string name; float fee;
	int i=1;
	ifstream my_file("input.txt");
	while(my_file.good()){
		my_file >> id;
		my_file >> name;
		my_file >> fee;
		cout << "Student " << i++ << " : " << endl;
		cout << id << endl << name << endl << fee << endl;
		cout << "\n-------------\n";
	}
	return 0;
}
