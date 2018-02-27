#include <iostream>
#include <ctime>

using namespace std;



//prints out an array
void printArray( int *arr, int n);

//checks if array is sorted or not
bool isSorted(int *arr, int n);

int main ()
{
    int arrSize = 5;
    int *arr = new int[arrSize];        //allocate memory for array
 
    srand(time(0));         //will make rand() produce different number each time we ran the app
    //assign values to an array 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 10 +1;  // rand() % 10 <-- random between 0 and 9
                                    // + 1 << will show random between 1 - 10
    }

    //prints out array members
    printArray(arr, arrSize);

    //sorts the array 
    if ( isSorted(arr, arrSize) == true) 
            cout << endl << "array is sorted";
        else
            cout << endl << "array not sorted";
    

    delete[] arr;

    return 0;
}


void printArray( int *arr, int n)
{
    cout << endl << "Arr values: ";
    for (int i = 0; i < n; i++)  {
        cout << arr[i] << " ";
    }

    return;
}

bool isSorted(int *arr, int n)
{

    for (int i=0; i < n-1; i++)  //n - 1 for boundry errors 
    {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}