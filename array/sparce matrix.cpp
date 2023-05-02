#include<iostream>

using namespace std;


void transpose ( int a[5][6] ){
	int temp = 0;
	
        
        	
}

int main()
{
    int sparseMatrix[5][6] =
    {
        {0 , 0 , 0 , 0 , 9, 0 },
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };

    // Finding total non-zero values in the sparse matrix
    int size = 0;
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 6; column++)
            if (sparseMatrix[row][column] != 0)
                size++;

    // Defining result Matrix
    int resultMatrix[size][3];

    // Generating result matrix
    int k = 0;
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 6; column++)
            if (sparseMatrix[row][column] != 0)
            {
                resultMatrix[k][0] = row;
                resultMatrix[k][1] = column;
                resultMatrix[k][2] = sparseMatrix[row][column];
                k++;
            }

    // Displaying result matrix
    cout<<"Triplet Representation : "<<endl;
    for (int row=0; row<size; row++)
    {
        for (int column = 0; column<3; column++)
            cout<<resultMatrix[row][column]<<" ";

        cout<<endl;
    }
    
    cout << "\n------------------\n";
    
    int temp=0;
    for (int row = 0; row < 5; row++){
		for (int column = 0; column < 6; column++){
			cout << sparseMatrix[row][column] << " ";
				
		}
		cout << endl;
	}
    
    cout << "\n------------------\n";
    
    cout<<"Triplet Representation : "<<endl;
    for (int row=0; row<size; row++)
    {
        for (int column = 0; column<3; column++)
            cout<<resultMatrix[row][column]<<" ";

        cout<<endl;
    }
    
    return 0;
}
