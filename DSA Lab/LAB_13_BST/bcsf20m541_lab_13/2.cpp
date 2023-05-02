#include<iostream>
#include<fstream>
using namespace std;

class Student{
private:
	int stdId; 
	string name; 
	float fee; 
	Student* left; 
	Student* right; 
public:
	Student ( int stdId, string name, float fee, Student* left, Student* right ){
		this->stdId = stdId;
		this->name = name;
		this->fee = fee;
		this->left = left;
		this->right = right;
	}
	friend class StudentBST;
};

class StudentBST{
private:
	Student* root; 
public:
	StudentBST(){
		root=NULL;
	}
	bool insert (int stdId, string name, float balance){
		Student* newStudent = new Student (stdId,name, balance, NULL,NULL);
		Student* curStudent = root;
		Student* preStudent = NULL;
		int flag=1;
		while(curStudent!=NULL){
			preStudent = curStudent;
			if(stdId==curStudent->stdId){
				flag=0;
				break;
			}
			else if(stdId<curStudent->stdId) {
				curStudent=curStudent->left; 
			}
			else {
				 curStudent=curStudent->right; 
			}
		}
		if(flag!=0){
			if(preStudent==NULL) 			 root=newStudent;
			else if(preStudent->stdId>stdId) preStudent->left=newStudent;
			else 							 preStudent->right=newStudent;
			return true;
		}
		else return false;
	}
	//~StudentBST(); 
};


int main(){
	StudentBST b1;
	int id; string name; float fee;
	ifstream my_file("input.txt");
	while(my_file.good()){
		my_file >> id;
		my_file >> name;
		my_file >> fee;
		if(b1.insert(id,name,fee))	cout << "Student data Successfully Inserted\n";
		else						cout << "Student with this ID already exists\n";
		cout << "\n------------\n";
	}
	return 0;
}
