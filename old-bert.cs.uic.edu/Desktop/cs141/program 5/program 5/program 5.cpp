#include <iostream>

using namespace std;

void info()
{
	cout << 
"Author: Hubert Budzik				\n\
Program : #5, AcrossWords			\n\
TA : Michael Irizarry Tuesday 5pm	\n\
April 15, 2017						\n\
									\n\
Welcome to AcrossWord puzzle, where you rotate rows or columns			\n\
to restore the board back to containing four words.Each move is			\n\
a row or column letter followed by the rotation distance 1, 2 or 3.		\n\
														\n\
When prompted to provide input you may enter :							\n\
		Enter 'r' to reset the board to user - defined values.			\n\
		Enter 'u' to unveil the underlying words.						\n\
		Enter 's' to auto solve the board(Extra Credit)					\n\
		Enter 'x' to exit the program"							
	<< endl;					
}

int main()
{	
	//This function will print initial instructions
	info();

	//setting up dynamic array here
	char dictionary[10];

	FILE * pFile;
	pFile = fopen("smallDictionary.txt", "r");

	
	


	
	

	

	

	//this stops the program from going cray cray at the end 
	getchar();

    return 0;
}

