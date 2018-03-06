#include <iostream> 

using namespace std;


// this function will populate the list
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
		count++;
		
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


// this function will print out he list
void arrPrint(int *arr)
{
	int i = 0; 
	do{
	   cout << arr[i] << "\t";
	   if (i % 10 == 0)
	   {
	      cout << endl;
	   }
	}while( arr[i++] != -999 );
cout <<endl;
return;
}

int bsearchR(int* &arr, int lo, int hi, int target)
{
cout << "lo: " << lo << endl;
cout << "hi: " << hi << endl;

int a = 0;
//base case
if ( hi<lo )
	{
	cout << a++ << " ";
	return -1;
	}

//recursive call
	int middle = (lo+hi) / 2;
cout << "middle: " << middle << endl << endl;	
	// if middle turns out to be the target we are searching for
	if (arr[middle] == target){
		return middle;
	}else if( target  < arr[middle] ){
		return bsearchR(arr, lo, middle - 1, target); //checks the left side 
	}else{
		return bsearchR(arr, middle + 1, hi, target); // checks the right side
	}
}


				/* *** MAIN START *** */
int main(int argc, char** argv)
{

// creating dynamic array
int n = 4;
int count = 0; 

int *arr = new int[n];
// populate the array 
arrpopulate(arr, n, count);

// print the sorted list
arrPrint(arr);

cout << endl;
cout << "Target selected: 511" << endl;
int x = 511;
int y = bsearchR(arr, 0, count -2, x);
cout << "Target located at arr[" <<  y  << "]: " << arr[y];
cout << endl;
return 0;
}
