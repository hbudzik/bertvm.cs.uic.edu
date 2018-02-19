#include <stdio.h>
#include <stdlib.h>


//		this function copies values from one array to another
int arrayCopy (	
					int fromArray[], 
					int toArray[], 
					int size
				)
{
	
	
	printf("\n*** inside arrayCopy() function***\n");
	int i;
	for (i = 0; i < size; i++)
	{
		toArray[i] = fromArray[i];
	}
	return;
}


// 		This function  will use sorting algorithm to sort an array in ascending order
// INSERTION SORT
void myFavorateSort(
					int array[],
					int size
					)
{
		printf("\n*** inside myFavorateSort() function***\n");
		int i = 1, temp;
		
		while (i < size)
		{
			int j = i;
			while (j > 0 && array[j - 1] > array[j])
			{
				//swap 
					temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
					
				j = j - 1;		//keep swaping until untill it reaches smaller number below it
			}//end while
		i++;					//moves up to next position 
		}//end while				
}


// 		This function will perform a LINEAR SEARCH on the unsorted array and return 2 values.
// 1) the position in the array where the value was found or -1 if the value was not found 
// 2)number of comparisons needed to determine if/where the value is located in the array
int linSearch (
					int array[],		//	array full of numbers 
					int size,			//  size of array[] array
					int target,
					int* numComparisons
				)
{

		
	
	int i = 0;
	
	do
	{
		*numComparisons += 1;
		i++;
	} while ( i < size && array[i] != target);
	if ( array[i] == target)
	{
		*numComparisons += 1;

	}
		return *numComparisons;
}


// 		This function will perform a BINARY SEARCH on the unsorted array and return 2 values.
// 	1) the position in the array where the value was found or -1 if the value was not found 
// 	2)number of comparisons needed to determine if/where the value is located in the array
int binSearch (
					int array[],
					int size,
					int target,
					int* binComparisons
				)
{
	*binComparisons = 0;	//reseting variable after linear search
	
	int L = 1;
	int R = size;
	int middle = (L + R)/2;
		
		while(target != array[middle - 1] && L < R)
		{			
			++*binComparisons;
			if (array[middle - 1] < target)
			{
				L = middle + 1;
				middle = (L + R)/2;
			}else
			{
				R = middle - 1;
				middle = (L + R)/2;
			}
		}
	++*binComparisons;
	return *binComparisons;
}
		
		
int main()
{
	
int val;	//user input variable

//declare array and allocate memory on the heap
int* originalArray = NULL;
int* temp = NULL;
int* copyArray = NULL;
int* testVal = NULL;

/************************* DYNAMIC MEMORY ALLOCATION START **************************/

//		Here array memory will be allocated dynamicaly using realloc() function
printf ("Enter in a list of numbers followed by the terminal value of -999: ");

int count = 0;		//counts number of inputs from scanf
do 
{	
    scanf("%d", &val);
    if (val == -999) { 	break;}
    count++;
	temp = (int *) realloc(originalArray, count * sizeof(int));
	originalArray = temp;
	originalArray[count -1] = val;	
}while (val != -999);

// 	populate list with values that will be compared agains list
printf ("Enter in a list of numbers to be compared followed by the terminal value of -999: ");

int countTest = 0;	//counts amount of numbers that will be compared of inputs from scanf
do 
{	
    scanf("%d", &val);
    if (val == -999) { 	break;}
    countTest++;
	temp = (int *) realloc(testVal, countTest * sizeof(int));
	testVal = temp;
	testVal[countTest -1] = val;	
}while (val != -999);

/****	calls function to copy array	***/
copyArray = (int *) malloc(count * sizeof(int));
arrayCopy(originalArray, copyArray, count);

/****	calls function to sort an array in ascending order	****/
myFavorateSort(originalArray, count);
	
/*** here we will print out the array size and its values ***/
printf("\nArray size: %d", count);
printf("\n");
    int j;
	printf("Array values:");
	
	for (j=0; j < count; j++)
	{
		printf(" %4d,", 	copyArray[j]);	
		if (j % 10 == 0) 
			printf("\n");
	}
	
// printf values that will be compared against the list

printf("\nArray size: %d", countTest);
printf("\n");
    
	printf("Array values:");
	for (j=0; j < countTest; j++)
	{
		printf(" %4d,", 	testVal[j]);
			if (j % 10 == 0) 
				printf("\n");	
	}
	
	
	
//		calls function to perform linear search and locate its position and number of comparisons needed to accomplish that


//		calls 2 functions to perform linear search on original array than binary search on original array, and count howmany comparisions were performed before target number was found.

int numComparisons = 0;		//value that will be stored informing us how many comparisons linear search went through before target was found

	
printf("\n\n");
int z;
for (z = 0; z < countTest; z++)
{
printf("\n");
printf("Linear search ->>>\tTarget: %d \t Comparisons: %d \n", testVal[z], linSearch(originalArray, count, testVal[z], &numComparisons));
printf("Binary search ->>>\tTarget: %d \t Comparisons: %d \n", testVal[z], binSearch(originalArray, count, testVal[z], &numComparisons));	
}

	
//		freeing allocated memory
free(originalArray);
free(copyArray);


printf("\n");




printf("\n");
return 0;
}
