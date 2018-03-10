#include <iostream>


using namespace std;
bool DEBUFF = false;	//for debugging


// prints out the array
void arrPrint(int *arr);


//will populate the array 
void arrpopulate(int* &arr, int n, int &count);


//quick sort 
void qsort(int* &arr, int l, int r);


int main(int argc, char** argv)
{

if ( argc == 1)
{	
	
	cout << "no input" << endl;
	return 0;
}


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
arrPrint(arr);

cout << "count: " << count << endl;

//sort using quick sort method
qsort(arr, 0, count -1);

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

//swap function used by qsort
void swap(int* &arr, int i, int j);

//quick sort 
void qsort(int* &arr, int l, int r)
{
    int i, j, pivot;

    if (r <= l){
        return;
    }
    if (r == l+1){
        if(arr[l] > arr[r])
            {
                swap(arr, l, r);
            }
        return;
    }

    //median-of-three
    //picks 3 numbers and 
    int middle = (l+r) / 2;
    if (arr[middle] < arr[l]){
        swap (arr, l, middle);
    }
    if (arr[r] < arr[l]){
        swap (arr, r, l);
    }
    if (arr[r] < arr[middle]){
        swap (arr, r, middle);
    }
    swap(arr, middle, r-1);        // pivot at position r-1, moved from middle(center)
    pivot = arr[r-1];

    //start sorting 
    i = l;
    j= r-1;
    for(;;){
        while(arr[++i] < pivot);
        while(arr[--j] > pivot);
        if(i >= j){ break; }
        swap(arr, i, j);
    }
    swap(arr, i, r-1);    //replace pivot

    //recursion
    qsort(arr, l, i-1);
    qsort(arr, i+1, r);


    return;
}


void swap(int* &arr, int i, int j)
{
    int tmp;

    tmp  = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
