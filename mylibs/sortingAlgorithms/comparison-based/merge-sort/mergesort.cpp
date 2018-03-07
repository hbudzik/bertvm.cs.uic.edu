#include <iostream>


using namespace std;
bool DEBUFF = false;	//for debugging


// prints out the array
void arrPrint(int *arr);


//will populate the array 
void arrpopulate(int* &arr, int n, int &count);


//merge sort method
void msort_intR(int* &arr, int lo, int hi, int* &scratch);


int main(int argc, char** argv)
{

for (int z = 1; z < argc; z++)
{
	//processing input flags
	if ( argv[z][0] != '-' ) { 
		cout << "wrong input .. gry -h for help.. " << endl;
		return 0;
	}else if ( argv[z][1] == 'h' ) {
		cout << "prints out -h info help info " << endl;
		break;
	}else if ( argv[z][1] == 'd' ) {
		cout << "DBUGG MODE: ON " << endl;
		DEBUFF = true;
		continue;
	}else{
		cout << "-" << argv[z][1] << " is not recognized parameter " << endl;
		return 0;
	}
}

//creating dynamic array
int n = 5;
int count = 0;
int *arr = new int[n];

//populating the array 
arrpopulate(arr, n, count);

//prints out the array
//cout << "original array count: " << count << endl;
//arrPrint(arr);

//sort the array using mergesort method

cout << "count: " << count << endl;

int* scratch = new int[count];
msort_intR(arr, 0, count -1, scratch);		//count -1 if ending digit -999 is included 
delete[] scratch;

//prints the list after 
arrPrint(arr);
return 0;
}


void arrPrint(int *arr)
{
	int i = 1; 
	do{
	   cout << arr[i-1] << "\t";
	   if (i % 10 == 0)
	   {
	      cout << endl;
	   }
	}while( arr[i++] != -999 );

cout <<endl;
return;
}


void arrpopulate(int* &arr, int n, int &count)
{
	int i=0;
	int input;
	
	do
	{
		// takes user input and plugs it into an array 
		cin >> input;		
		arr[i] = input;
		i++;		

		if ( input != -999 ){
				count++;
		}


		//checks if arr is full	
		if (n == i)
		{
			// new array with double the size in memory  
			int *newarr = new int[n * 2];	//doubles the size 
		        	
			//deep copy data from old array to new larger array
			for (int k = 0; k < n; k++)
			{
				newarr[k] = arr[k]; 			 
			}
			delete[] arr;
			n = 2*n;			
			arr = newarr;
		}
	} while (input != -999);

cout << endl;	
return;
}


void msort_intR(int* &arr, int lo, int hi, int* &scratch)
{
	
	//base case if list only contains 0 or 1 element than its sorted  
	if ( lo >= hi ){
		return; 
		}

	// "N" = hi-lo +1
	//spliting the array in half
	int middle = (hi + lo) / 2;

	//recursion
	msort_intR(arr, lo, middle, scratch);
	msort_intR(arr, middle+1, hi, scratch);


	int i = lo; 			// lhs index
	int j = middle + 1;		// rhs index
	int k = 0;				// index into scratch[] array that will temporarly store sorted array


	while( i <= middle && j <= hi ) {
			if (arr[i] <= arr[j]) {
				scratch[k] = arr[i];
				i++;
			}
			else{
				scratch[k] = arr[j];
				j++;
			}
			k++;
		}
	
	//copy leftovers
	while ( i <= middle ) {
		scratch[k] = arr[i];
		i++;
		k++;
	}
	while (j <= hi) {
		scratch[k] = arr[j];
		j++;
		k++;
	}

	//copy back to an original array
	for (k = 0, i=lo; i<=hi; i++, k++)
	{
		arr[i] = scratch[k];
	}
	return;
}
