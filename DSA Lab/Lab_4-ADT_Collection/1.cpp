#include<iostream>
using namespace std;

class Collection {
private:
	int *data;
	int size;
public:
	
	Collection (  ){	}
	
	Collection ( int s ){
		if ( s>0 )	size = s;
		else 		size = 0;
		
		data = new int[size];	
	}
	
	Collection ( int s, int *arr){
		if ( s>0 )	size = s;
		else 		size = 0;
		data = new int[size];
		for ( int i=0; i<size; i++){
			if (arr[i] > 0)		data[i] = arr[i];
			else data[i] = 0;
		}
	}
	
	Collection ( const Collection &c ){
		cout << "Copy\n";
		this->size = c.size;
		this->data = new int[size];
		for ( int i=0; i<c.size; i++)
			this->data[i] = c.data[i];
}
	
	int getsize ( ){
		cout << "Size is: " << size << endl;
	}
	
	void printCollection ( ){
		cout << "Array is: ";
		for ( int i=0; i<size; i++)
			cout << data[i] << " ";
		cout << endl;
	}
	
	void get_collection ( int s ){
		if ( s>0 )	size = s;
		else 		size = 0;
		if ( size>0){
		data = new int[size];
		for ( int i=0; i<size;  i++){
			cout << "Enter Number " << i+1 << ": ";
			cin >> data[i]; }
	}
}

	void insert_element ( int value, int index ){
		if ( index<=this->size ){
			data[index] = value;
		}
		else cout << "Index is Invalid\n";
	}
	
	bool find_Element ( int value ){
		int flag=0;
		for ( int i=0; i< size; i++ ){
			if ( data[i] == value ){
			flag = 1;
			return true;
			break;
		}
		if ( flag==0) 	return true;;
	}
}

	Collection& operator = ( const Collection &c ){
		cout << "Assign\n";
		if ( c.size!=this->size ){
			this->size = c.size;
			this->data = new int[size];
		}
		for ( int i=0; i<c.size; i++){
			this->data[i] = c.data[i];	
		}
			
}

	Collection operator + ( const Collection &c ){
		Collection Newp;
		Newp.size = c.size;
		Newp.data = new int[c.size];
		if ( c.size == this->size )	{
			for ( int i=0; i<c.size; i++)
				Newp.data[i] = this->data[i] + c.data[i]; 
		return Newp;
		}
		else {
			cout << "Addition Not possible\n";
			this->size = -1;
			data = NULL;
		}	
	}
	
	bool operator == ( const Collection &c ){
		int count=0;
		for ( int i=0; i<c.size; i++ ){
			if ( this->data[i] == c.data[i]  )	count ++;
			else {	return false;
					break;  }
		}
		if ( count==size ) 	return true;
	}
	
	~Collection (  ){	delete data;		}
	
	
};

int main () {
	//checking const1 and getsize function
	int size, value, index;
	int array[10] = { 1,2,3,4,5,6,7,8,9,10};
//	Collection c1(5);
//	c1.getsize();
//	cout << "\n---------\n";
	
	//checking const2 and print collection
	cout << "Working on C2: \n";
	Collection c2(10, array);
	c2.getsize();
	c2.printCollection();
	cout << "\n---------\n";
	
//	//Another check
//		cout << "Working on C3: \n";
//	Collection c3(5, array);
//	c3.getsize();
//	c3.printCollection();
//	cout << "\n---------\n";
	
	//testng get_collection 
//	cout << "Enter size: ";
//	cin >> size;
//	c3.get_collection(size);
//	c3.getsize();
//	c3.printCollection();
	
//	//Copying in new object
//		cout << "Working on C4: \n";
//	Collection c4 = c2;
//	c4.printCollection();
//	cout << "\n---------\n";
//	
//	//Checking insert function
//	cout << "Inserting value: \n";
//	cout << "Enter value: ";
//	cin >> value;
//	cout << "Enter Index: ";
//	cin >> index;
//	c4.insert_element(value,index);
//	c4.printCollection();
//	cout << "\n---------\n";
//	
//	//Check find element
//	cout << "Enter Value: ";
//	cin >> value;
//	if (c4.find_Element(value))		cout << "Element Fount\n";
//	else 						cout << "Element Not Fount\n";
	
	Collection c3(5);
	
	//Checking assignment operator
	c3 = c2;
	cout << "Assigning values of C2 to C3: \n";
	c3.printCollection();
	
	//Adding two arrrays
	cout << "\n---C3 + C2: \n";
	cout << "C2: ";
	c2.printCollection();
	cout << "C3: ";
	c3.printCollection();
	Collection c4 = c3+c2;
	cout << "After additon of c2 and c3 values are: \n";
	c4.printCollection();
	
	//Check for ==
	cout << "\n--Check c2==c3\n";
	if( c2==c3 )			cout << "Both are Equal\n";
	else					cout << "Both are Not Equal\n";
	return 0;
}
