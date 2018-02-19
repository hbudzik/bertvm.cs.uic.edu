#include <stdio.h>

//this function will be used to display updated board
void boardDisplay(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15)
{	
	printf("-----------------------\n");
	printf("  board    Position\n");
	printf("    %c          A          \n", p1);
	printf("   %c %c        B C          \n", p2, p3);
	printf("  %c %c %c      D E F          \n", p4, p5, p6);
	printf(" %c %c %c %c    G H I J          \n", p7, p8, p9, p10);
	printf("%c %c %c %c %c  K L M N O          \n\n", p11, p12, p13, p14, p15);
}


int checkValidSourcePeg(char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15, char sourcePeg)
{

	switch (sourcePeg)
	{
	case 'A': if (*p1 == 'o') { return 0; }
			  else { return 1; }
	case 'B': if (*p2 == 'o') { return 0; }
			  else { return 1; }
	case 'C': if (*p3 == 'o') { return 0; }
			  else { return 1; }
	case 'D': if (*p4 == 'o') { return 0; }
			  else { return 1; }
	case 'E': if (*p5 == 'o') { return 0; }
			  else { return 1; }
	case 'F': if (*p6 == 'o') { return 0; }
			  else { return 1; }
	case 'G': if (*p7 == 'o') { return 0; }
			  else { return 1; }
	case 'H': if (*p8 == 'o') { return 0; }
			  else { return 1; }
	case 'I': if (*p9 == 'o') { return 0; }
			  else { return 1; }
	case 'J': if (*p10 == 'o') { return 0; }
			  else { return 1; }
	case 'K': if (*p11 == 'o') { return 0; }
			  else { return 1; }
	case 'L': if (*p12 == 'o') { return 0; }
			  else { return 1; }
	case 'M': if (*p13 == 'o') { return 0; }
			  else { return 1; }
	case 'N': if (*p14 == 'o') { return 0; }
			  else { return 1; }
	case 'O': if (*p15 == 'o') { return 0; }
			  else { return 1; }
	
	}
}


int checkValidDestinationPeg(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15, char destinationPeg)
{

	switch (destinationPeg)
	{
	case 'A': if (p1 == '+') { return 0; }
			  else { return 1; }
	case 'B': if (p2 == '+') { return 0; }
			  else { return 1; }
	case 'C': if (p3 == '+') { return 0; }
			  else { return 1; }
	case 'D': if (p4 == '+') { return 0; }
			  else { return 1; }
	case 'E': if (p5 == '+') { return 0; }
			  else { return 1; }
	case 'F': if (p6 == '+') { return 0; }
			  else { return 1; }
	case 'G': if (p7 == '+') { return 0; }
			  else { return 1; }
	case 'H': if (p8 == '+') { return 0; }
			  else { return 1; }
	case 'I': if (p9 == '+') { return 0; }
			  else { return 1; }
	case 'J': if (p10 == '+') { return 0; }
			  else { return 1; }
	case 'K': if (p11 == '+') { return 0; }
			  else { return 1; }
	case 'L': if (p12 == '+') { return 0; }
			  else { return 1; }
	case 'M': if (p13 == '+') { return 0; }
			  else { return 1; }
	case 'N': if (p14 == '+') { return 0; }
			  else { return 1; }
	case 'O': if (p15 == '+') { return 0; }
			  else { return 1; }
	
	}

}
void setPiece(char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15, char destinationPeg)
{
	switch (destinationPeg)
	{
	case 'A': *p1 = 'o'; return;
	case 'B': *p2 = 'o'; return;
	case 'C': *p3 = 'o'; return;
	case 'D': *p4 = 'o'; return;
	case 'E': *p5 = 'o'; return;
	case 'F': *p6 = 'o'; return;
	case 'G': *p7 = 'o'; return;
	case 'H': *p8 = 'o'; return;
	case 'I': *p9 = 'o'; return;
	case 'J': *p10 = 'o'; return;
	case 'K': *p11 = 'o'; return;
	case 'L': *p12 = 'o'; return;
	case 'M': *p13 = 'o'; return;
	case 'N': *p14 = 'o'; return;
	case 'O': *p15 = 'o'; return;
	}
}

void jumpPiece(char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15, char jumpedPeg)
{
	
	
	switch (jumpedPeg)
	{
	case 'A': *p1 = 'o'; return;
	case 'B': *p2 = 'o'; return;
	case 'C': *p3 = 'o'; return;
	case 'D': *p4 = 'o'; return;
	case 'E': *p5 = 'o'; return;
	case 'F': *p6 = 'o'; return;
	case 'G': *p7 = 'o'; return;
	case 'H': *p8 = 'o'; return;
	case 'I': *p9 = 'o'; return;
	case 'J': *p10 = 'o'; return;
	case 'K': *p11 = 'o'; return;
	case 'L': *p12 = 'o'; return;
	case 'M': *p13 = 'o'; return;
	case 'N': *p14 = 'o'; return;
	case 'O': *p15 = 'o'; return;
	}
}

void getPiece(char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15, char sourcePeg)
{
	switch (sourcePeg)
	{
	case 'A': *p1 = '+'; return;
	case 'B': *p2 = '+'; return;
	case 'C': *p3 = '+'; return;
	case 'D': *p4 = '+'; return;
	case 'E': *p5 = '+'; return;
	case 'F': *p6 = '+'; return;
	case 'G': *p7 = '+'; return;
	case 'H': *p8 = '+'; return;
	case 'I': *p9 = '+'; return;
	case 'J': *p10 = '+'; return;
	case 'K': *p11 = '+'; return;
	case 'L': *p12 = '+'; return;
	case 'M': *p13 = '+'; return;
	case 'N': *p14 = '+'; return;
	case 'O': *p15 = '+'; return;
	}
}

int main()
{
	printf("Author: Hubert Budzik\n");
	printf("Assignment: 2, PegJump\n");
	printf("TA : Karla Templar, Tues 10\n");
	printf("Jan 25, 2017\n\n");
	printf("This program represents the peg jumping puzzle.\n\n");
	printf("The board starts out with a single blank position, represented by\n");
	printf("the 'O'.To make a move, select the letter of the peg to be moved,\n");
	printf("then the letter of the destination position. (e.g.the first move\n");
	printf("might be : d a, meaning we move peg ‘d’ into blank position ‘a’.)\n");
	printf("A peg must be able to jump over an adjacent peg into a blank for a\n");
	printf("move to be valid.The jumped peg is then removed from the board.\n");
	printf("The game is over when there are no valid moves left to be made, or\n");
	printf("when there is a single peg left.\n\n");
	printf("At any point enter 'x' to exit the program.\n\n");

	//here we will declare and initialize variable for the board
	char p1 = 'o';
	char p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15;
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+';
	int movesCount = 1;
	int validity;
	char destinationPeg, sourcePeg, jumpedPiece;	
	
	while (1)
	{
		//callls function boardDisplay() and displays an updated board
		boardDisplay(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

		//here a user will be asked for input and values will be stored in variables
		printf("\n");
		printf("%d. Enter your move: ", movesCount);
		scanf_s("%c", &sourcePeg);

		//this will exit the while loop if user inputs 'x'
		if (sourcePeg == 'x') { printf("exiting now... \n"); getchar(); break; }
		scanf_s(" %c", &destinationPeg);
		movesCount++;


		//here we will check the validity of our sourcePeg peg and its destinationPeg
		validity = checkValidSourcePeg(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, sourcePeg);
		if ( validity == 1) 
		{ 
			printf("   *** Invalid sourcePeg.  Please retry ****\n");
			continue; 
		}

		validity = checkValidDestinationPeg(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, destinationPeg);
		if ( validity == 1)
		{
			printf("   *** already occupied destinationPeg.  Please retry ****\n"); 
			continue;
		}

	
		
		char jumpedPeg = (sourcePeg + destinationPeg) / 2;

		//this function will set the selected position (validity should be checked )
		setPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, destinationPeg);
		
		//this function will get the piece and put it back on the board for use
		getPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, sourcePeg);
			
		//this function will turn the piece that is being jumped over to 'o'
		jumpPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, jumpedPeg);
			
		
		getchar();
	}//end of while loop.
    return 0;
}

