#include <stdio.h>
#include <string.h>
#include "testString.h"

int main()
{
	
	//case 1 variables 
	//***********************
	char aWord[100];
	char cUserInput = 'Y', cChar;
	int iOptionInput = 1, iLen = 0, iIndex = 0, iIsPalindrome = 0;
	//***********************

	int firstChoice;	//first switch variable
	int iUserInput;		//second switch variable

	
	do
	{
	printf("What would you like to do: \n\
			1. Evaluate a string		");
	
	scanf_s("%d", &firstChoice);

		switch (firstChoice)
		{
		case 1:
		{
			printf("Select the function you want to use:\n\
                1. Calculate length of a string\n\
                2. Find the position of a character in a string\n\
                3. Check if the string is a palindrome\n\
                Your choice:");
			scanf_s("%d", iUserInput);

			switch (iUserInput)
			{
			case 1: 
			{
				do
				{
				printf_s("Select the function you want to use:\n\
							1. Calculate length of a string\n\
							2. Find the position of a character in a string\n\
							3. Check if the string is a palindrome\n\
							Your choice:");
					scanf("%d", &iOptionInput);
					switch (iOptionInput)
					{
					case 1:
						printf("Please enter a string: ");
						scanf("%s", aWord);
						iLen = myStrLen(aWord);
						printf("Length of the string \"%s\" is %d\n", aWord, iLen);
						break;
					case 2:
						printf("Please enter a string: ");
						scanf("%s", aWord);
						printf("Please enter a character to search:");
						scanf(" %c", &cChar);
						iIndex = positionOfCharInWord(aWord, cChar);
						if (iIndex != -1)
						{
							printf("Position of '%c' in \"%s\" is %d\n", cChar, aWord, iIndex);
						}
						else
						{
							printf("'%c' is not found in \"%s\"\n", cChar, aWord);
						}
						break;
					case 3:
						printf("Please enter a string: ");
						scanf("%s", aWord);
						iIsPalindrome = isPalindrome(aWord);
						if (iIsPalindrome)
						{
							printf("Congratulations! \"%s\" is a palindrome!!\n", aWord);
						}
						else
						{
							printf("Sorry! \"%s\" is not a palindrome!!\n", aWord);
						}
						break;
					default:
						printf("Sorry, you have given an invalid option!!\n");
						break;
					}
					printf("Would you like to start again? [Y/N] :");
					scanf(" %c", &cUserInput);
				} while ((cUserInput == 'Y') || (cUserInput == 'y'));
			}//end of case 1
			}//and of switch 2
		}//end of case 1
		}//end of switch 
	} while ((cUserInput == 'Y') || (cUserInput == 'y'));



	return 0;
}

