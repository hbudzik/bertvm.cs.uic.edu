#include <stdio.h>
#include <stdlib.h>

int main()
{
	int counter = 5;
	int *pCounter = NULL;
	
	
	
	fprintf(stdout, "*pCounter: %d\n", *pCounter);
	fprintf(stdout, "sizeof(int): %d", sizeof(int));
	
	return 0;	
}
