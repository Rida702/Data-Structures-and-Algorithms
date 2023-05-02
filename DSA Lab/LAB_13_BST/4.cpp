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
	
	bool search (int stdId){
		Student* curStudent = root;
		int flag=0;
		while(curStudent!=NULL){
			if(stdId==curStudent->stdId){
				cout << "Student ID: " <<  curStudent->stdId << endl;
				cout << "Student Name: " <<  curStudent->name << endl;
				cout << "Student Fee: " <<  curStudent->fee << endl;
				flag=1;
				break;
			}
			else if(stdId<curStudent->stdId) {
				curStudent=curStudent->left; 
			}
			else {
				 curStudent=curStudent->right; 
			}
		}
		if(flag==0) return false;
		else return true;
	}
	
	void inOrder (){
		inOrder (root);
	}
	
	void inOrder (Student* stree){
		if(stree!=NULL){
			inOrder(stree->left);
			cout << stree->stdId << "\t";
			cout << stree->name << "\t";
			cout << stree->fee << "\n";
			inOrder(stree->right);
		}
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
		if(b1.insert(id,name,fee))	cout << "***Student data Successfully Inserted\n";
		else						cout << "###Student with this ID already exists\n";
	}
	b1.inOrder();
	cout << "\n----Searching----\n";
	if(b1.search(11)) cout << "Successfully Searched Student Data\n";
	else			cout << "Student Data Not Found\n";	
	return 0;
}
