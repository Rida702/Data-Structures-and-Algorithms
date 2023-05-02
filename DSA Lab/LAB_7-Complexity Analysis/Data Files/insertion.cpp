#include "iostream"
#include "fstream"
#include "ctime"

using namespace std;

//Add necessary instructions to count the Number of Key Comparsisons and Data Movements
//You are NOT Allowed to add any input/output instructions in sorting algorithms 

//Bubble Sort
void bubbleSort(int a[], int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
				
		}
	}
}

//Selection Sort
void selectionSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (a[min] > a[j])
				min = j;
		}

		swap(a[i], a[min]);
	}
}

//Insertion Sort
void insertionSort(int a[], int size)
{
	int j = 0,m=0;
	int count_comp = 0, count_data = 0;
	for (int i = 0; i < size - 1; i++)
	{
		j = i + 1;
		if(a[i]<=a[i+1])
		{
		count_comp++;
		m++;	
			}	
		while (j > 0 && a[j] < a[j - 1])
		{
			count_data++;
			swap(a[j], a[j - 1]);
			count_comp++;
			j--;
		}
	}
	if(m!=count_comp)
	 count_comp=count_comp-m;
	cout << "\n-------\n";
	cout << "count_comp: " << count_comp << endl;
	cout << "\n-------\n";
	cout << "count_data: " << count_data << endl;
}

int main()
{
	fstream file_1;
	string line;
	int arraysize = 60000+1;
	int arr[arraysize], arr1[arraysize-1];
	int count=0;
	file_1.open("in6000a.txt", ios::in );
	while (count < arraysize && file_1 >> arr[count]){
        count++;
    }
    
//    for(int i=0;i<arraysize;i++){
//		cout << arr[i] << '\n'; }
	for(int i=0;i<arraysize;i++){
		if ( i>0) {
			arr1[i] = arr[i] ; 
		//	cout << arr1[i] << '\n';
		}
}
	clock_t startTime = clock();
	//Make a call to sorting algorithm. DO NOT perform any other operation here 
	insertionSort(arr1,arraysize-1);
	clock_t endTime = clock();
	double elapse = ((double)endTime - (double)startTime) / CLOCKS_PER_SEC;
	cout << "The operation took " << elapse << " seconds";

	//Add any other instructions here, if required


	return 0;
}
