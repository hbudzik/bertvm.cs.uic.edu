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
	int i = 1; 
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


// this will be used by isort function
//void insert(int* &arr, int &count)


// this function will sort the list using select sort algorithm 
int* isort(int* &arr, int &count)
{
	int* newSort = arr;
	int tmp;

	for (int i=0; i < count; i++)
	{
		//insert(newSort, i);
		int x = arr[i];
		int j = i -1;
		while( j>=0 && x<arr[j] )
		{
			arr[j+1] = arr[j];	//slide left to right index, right index is stored in x
			j--;
		}
		arr[j+1] = x;	//previous idex is smaller therefore stopping at a[j+1]
	}

return newSort;
}


	/* *** MAIN START *** */
int main(int argc, char** argv)
{

if ( argc == 1 )
	{
		cout << "takes a list of elements and sorts them";
	}
// creating dynamic array
int n = 4;
int count = -1; 

int *arr = new int[n];
// populate the array 
arrpopulate(arr, n, count);

arrPrint(isort(arr, count));
    
cout << endl;
return 0;
}
