#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char nameArr[100];	//will store strings in this
	char newString[20];
	
	printf("Enter name: ");
	scanf("%s", nameArr);
	
	printf("You entered: %s\n", nameArr);
	printf("Number of strings in an array: %d\n\n", strlen(nameArr));
		
	char iChoice;
	int quit = 1;
	while (quit)
	{
		
		printf("would you like to add another string?(y/n): ");
		scanf(" %c", &iChoice);
		printf("\n");
		if (iChoice == 'y')
		{
			printf("Enter new String: ");
			scanf("%s", newString);
			
			
			strcat(nameArr, " ");
			strcat(nameArr, newString);
			
			printf("New string *** %s ***\n", nameArr);
			printf("Number of strings in an array: %d\n\n", strlen(nameArr));
			
			
		}else if (iChoice == 'n')
		{
			quit = 0;
		}else
		{		
			printf("Wrong choice!");
			continue;
		}
	}
	
	return 0;
	
}
