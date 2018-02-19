#include <stdio.h>
#include <stdlib.h>


/*
int arrayCopy (int originalArray[], int size)
{
	int* cloneArray = (int *) malloc(size*sizeof(int));
	
	
    int i;
    for (i = 0; i < size; i++)
    {
        cloneArray[i] = originalArray[i];
    }
    return cloneArray;
}*/

void foo(unsigned int n) {

    printf("tick\n");
    if(n > 0) {
        foo(n-1);
        foo(n-1);
    }
}  



int main()
{

foo(1);
	return 0;
}
