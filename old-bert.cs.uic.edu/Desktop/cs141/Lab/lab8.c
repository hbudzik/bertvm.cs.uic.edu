#include <stdio.h>
#include <string.h>

/* Write your functions here. Do not use string.h functions.*/
int myStrLen(char aWord[100])
{
	return strlen(aWord);
}

//
int positionOfCharInWord(char aWord[100], char cChar)
{
	int length = strchr(aWord, cChar) - aWord;
	
	if(strchr(aWord, cChar) - aWord < 0) { return -1 ;}
	
	
	return length + 1;
}

int isPalindrome(char aWord[100])
{
	int i; int counter = 0;
	int stringLength = myStrLen(aWord);
	for (i=0; i < stringLength/2; i++ )
	{
		if (aWord[i] == aWord[stringLength - i -1])
		{
			counter++;
		}
		//checks if halfway
		if (counter == stringLength/2){ return 1;}
	}
	return 0;
}

int main()
{
    char aWord[100];
    char cUserInput = 'Y', cChar;
    int iOptionInput = 1, iLen = 0, iIndex = 0, iIsPalindrome = 0;

    do
    {
        printf("Select the function you want to use:\n\
                1. Calculate length of a string\n\
                2. Find the position of a character in a string\n\
                3. Check if the string is a palindrome\n\
                Your choice:");
        scanf("%d", &iOptionInput);
        switch(iOptionInput)
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
        scanf(" %c",&cUserInput);
    } while ((cUserInput == 'Y') || (cUserInput == 'y'));

    return 0;
}
