#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int totalLimit = 400;

void startingGuide()
{
	printf("\nAuthor: Hubert Budzik");
	printf("\nProgram : #4, Secret");
	printf("\nTA : Michael Irizarry, Tues 5pm");
	printf("\nMarch 18, 2017");
	printf("\n");
}


void convert1D	(	char array[],			//original 1d array
					char array2D[20][25],	//new 2d array 
					int limit				//number of characters in the 1d array
				)
{
	int i = 0;
	int j = 0;
	int row = 0;
	


	for (i = 0; i < limit; i++)
	{
		if (array[i] == ' ')
		{
			array2D[row][j] = '\0';
			row++;
			j = 0;
		}
		else
		{
			array2D[row][j] = array[i];
			j++;
		}

		if (array[i] == '\0')
		{			
			break;
		}
	}
}


const int keyLimit = 500;

int main()
{
//printing initial 
	startingGuide();

//reading in key.txt
	char keyArray[500];

	FILE * pKey;
	pKey = fopen("keys.txt", "r");
	fgets(keyArray, keyLimit, pKey);
	fclose(pKey);

//this function will check how many phrases in an array
	int length = 0;
	for (int i = 0; i < keyLimit; i++)
	{
		if (keyArray[i] == ' ') { length++; }
		else if (keyArray[i] == '\0') { length++;  break; }
	}


//turn it into 2d 
	char keyArray2D[20][25];
	convert1D(keyArray,	keyArray2D, keyLimit);

	printf("\n");
	printf("Read in 4 keyWords, which are:\n\n");
	for (int words = 0; words < length; words++)
	{
		printf("%s\n", keyArray2D[words]);
	}

//reading in cipher.txt
	printf("\n");
	printf("Read in 390 cipherText characters.\n\n");

	char cipherArray[400];
	char cipher2dArray[totalLimit][132];

	FILE * pFile;
	pFile = fopen("cipher.txt", "r");
	fgets(cipherArray, 400, pFile);
	fclose(pFile);

	char choice;
	int rows;
	int TF = 1;

//loop for the menu
	while (TF)
	{
		printf("						\n\
Choose from the following options :     \n\
1. Display a particular sized table		\n\
2. Find all matching key word phrases	\n\
X.Exit the program						\n\
Enter your choice -> ");
	
		scanf_s(" %c", &choice);
		choice = toupper(choice);

		switch (choice)
		{
		case '1':
		{
			//this function will display particular size table
			printf("\nEnter the row size: ");
			scanf_s(" %d", &rows);
			
			continue;
		}
		case '2':
		{
			//this fuction will search for the message
			choice = 'x';
			continue;
		}
		case 'X': { printf("\nexiting\n"); TF = 0;  break; }
		default:	{ printf("\n wrong choice. please try again!!!\n"); break; }
		}//end switch
	}//end while 

	system("\npause");
    return 0;
}

