#include <stdio.h>

int main()
{
	
	printf("Name: Hubert Budzik, Midterm 1, CS 141, Spring 2017\n");
	printf("The first two alues are 4 and 7.\n");
	
	int varOne = 4;
	int varTwo = 7;
	
	printf("Enter how many additional values to be displayed: ");
	
	int additionalValues;
	scanf(" %d", &additionalValues);
	
	int x;
	int varAll[additionalValues];
	varAll[0] = 4;
	varAll[1] = 7;
 		int i;
 		int counter= 0;
 		printf("Additional values are:");

	for (i = 2; i < (additionalValues + 2); i++){
		varAll[i] = varAll[i - 2] + varAll[i - 1];
		
		
		printf(" %d", varAll[i]);
		
		if (varAll[i] % 2 != 0)
			{ 
			counter++;
			}
		}
		printf("\nthere were %d add numbers", counter);
		printf("\ndone.");
	
	
	return 0;
}
