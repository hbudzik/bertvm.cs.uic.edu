#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char arrayIn[300];
	int arrayLength;
	
	printf("Enter your string: ");
	fgets(arrayIn, 300, stdin);
	
	arrayLength = strlen(arrayIn);
	printf("\nstrLen(): %i", arrayLength);
	int i;
	printf("\n");
	for (i=0; i<arrayLength; i++ )
	{
	  printf("\n arrayIn[%d]: %c", i, arrayIn[i]);
	  if (arrayIn[i] == ' ')
	  {
	  	printf("space");
	  }else if (arrayIn[i] == '\n')
	  {
	  	printf("EOL");
	  }
	}	
	return 0;
}

