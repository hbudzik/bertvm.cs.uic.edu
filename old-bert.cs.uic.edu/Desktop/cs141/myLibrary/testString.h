

/* Write your functions here. Do not use string.h functions.*/
int myStrLen(char aWord[100])
{
	return strlen(aWord);
}


int positionOfCharInWord(char aWord[100], char cChar)
{
	int length = strchr(aWord, cChar) - aWord;

	if (strchr(aWord, cChar) - aWord < 0) { return -1; }


	return length + 1;
}

int isPalindrome(char aWord[100])
{
	int i; int counter = 0;
	int stringLength = myStrLen(aWord);
	for (i = 0; i < stringLength / 2; i++)
	{
		if (aWord[i] == aWord[stringLength - i - 1])
		{
			counter++;
		}
		//checks if halfway
		if (counter == stringLength / 2) { return 1; }
	}
	return 0;
}