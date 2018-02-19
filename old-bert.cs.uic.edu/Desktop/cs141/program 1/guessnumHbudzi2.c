#include <stdio.h>

int info(void)
{
	printf("Author: Hubert Budzik\n Program: #1, Guess Number\nTA: Michael Irizarry, Tues 5pm\nJan 23, 2017\n"); 
	printf("Welcome to the number guessing game!\nIf you concentrate, sometimes you can connect to the electrons in the computer!\n");
	printf("Let's try it.  Think of a three digit number. (To make it harder, make the digits\nall different from each other).");
}

//function userInput() will ask for a number and store it in a variable

int userInput(int number)
{
	printf("Type in your number: ");
	scanf("%d", &number);	
	return number;
}


int main()
{
	
	//declaring some variables 
	int userNumber;
	int reversedNumber = 0;
	int reminder;
	int originalNumber;
	char choice;
	
	//calls userInput() function for user input
	info();
	userNumber = userInput(userNumber);
	
	//if statement will not accept number if it has a repeating digit, is equal to 0 or larger than 999
	int a = userNumber % 10;
	int b = (userNumber / 10) % 10;
	int c = (userNumber / 100) % 10;
	
	if ( a == b || b == c || a == c || userNumber == 0 || userNumber > 999 )
	{
	printf("repeating number found exiting program now");
	printf("\n");	
		
	}else
	{			
		//while loop will reverse any number user inputs
		originalNumber = userNumber;
		
		while ( originalNumber != 0)
		{	
			reminder = originalNumber % 10;
			reversedNumber = reversedNumber * 10 + reminder;
			originalNumber = originalNumber / 10;	
		}
				
		//here we will substruct the larger number from the smaller one
		if ( userNumber > reversedNumber)
		{
			printf("\n");
			printf("  %d ", userNumber);
			printf("(the original number)\n");
			printf("- %d ", reversedNumber);
			printf("(the reversed number)\n");
			userNumber = userNumber - reversedNumber;
			printf("=====\n");
			printf("  %d", userNumber);
		}else
		{
			printf("\n");
			
			printf("  %d ", reversedNumber);
			printf("(the reversed number)\n");
			printf("- %d ", userNumber);
			printf("(the original number)\n");
			userNumber = reversedNumber - userNumber;
			printf("=====\n");
			printf("  %d", userNumber);
			
		}
			printf("\n");
			    		   							
				// here we will revere the number again and add it together
				originalNumber = userNumber;
				reversedNumber = 0; //reseting the value of this variable to 0
		
				while ( originalNumber != 0)
				{	
				reminder = originalNumber % 10;
				reversedNumber = reversedNumber * 10 + reminder;
				originalNumber = originalNumber / 10;	
				}
				
				printf("\nNow lets again scramble the numbers by reversing them, and adding them this time: \n");
				printf("  %d ", userNumber);
				printf("\n");
				printf("+ %d ", reversedNumber);
				printf("\n");
				userNumber = userNumber + reversedNumber;
				printf("=====\n");
				printf("  %d", userNumber);
				
				
			
				
		
				
					
		}	
	//This code will process all the numbers to see which will not be working 
	

	system("pause");
	return 0;
}
