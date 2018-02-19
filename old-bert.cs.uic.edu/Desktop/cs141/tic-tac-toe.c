#include <stdio.h> 

void displayFunction(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9)
{
	printf("\n");
	printf(" %c | %c | %c    1 2 3 \n", p1, p2, p3);
	printf(" %c | %c | %c    4 5 6 \n", p4, p5, p6);
	printf(" %c | %c | %c    7 8 9 \n", p7, p8, p9);
	printf(" ------------ \n");

}


int tieCheck(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9)
{
	if (p1 == '.' || p2 == '.' || p3 == '.' || p4 == '.' || p5 == '.' || p6 == '.' || p7 == '.' || p8 == '.' || p9 == '.')
	{
		return 0;
	}
	else
	{
		printf("Its a TIE !!\n");
		return 1;
	}
}


int playerTurn(int i)
{
	//positive indicates X, negative indicate O	
	if (i > 0)
	{
		printf("X turn! \n");
	}
	else
	{
		printf("O turn! \n");
	}
	return i;
}


int validatePosition(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, int choice)
{
	char validate = '.';
	switch (choice)
	{
	case 1: if (validate == p1) { return 1; }else { return 0; }
	case 2: if (validate == p2) { return 1; }else { return 0; }
	case 3: if (validate == p3) { return 1; }else { return 0; }
	case 4: if (validate == p4) { return 1; }else { return 0; }
	case 5: if (validate == p5) { return 1; }else { return 0; }
	case 6: if (validate == p6) { return 1; }else { return 0; }
	case 7: if (validate == p7) { return 1; }else { return 0; }
	case 8: if (validate == p8) { return 1; }else { return 0; }
	case 9: if (validate == p9) { return 1; }else { return 0; }
	}
}


int getUserMove()
{
	
	int move;
	scanf_s("%d", &move);
	return move;
}


int winnerIs(p1, p2, p3, p4, p5, p6, p7, p8, p9)
{
	if (p1 == 'X' && p2 == 'X' && p3 == 'X' || p4 == 'X' && p5 == 'X' && p6 == 'X' || p7 == 'X' && p8 == 'X' && p9 == 'X' || p1 == 'X' && p4 == 'X' && p7 == 'X' || p2 == 'X' && p5 == 'X' && p8 == 'X' || p1 == 'X' && p5 == 'X' && p9 == 'X' || p3 == 'X' && p5 == 'X' && p7 == 'X')
	{return 1;}
	else if (p1 == 'O' && p2 == 'O' && p3 == 'O' || p4 == 'O' && p5 == 'O' && p6 == 'O' || p7 == 'O' && p8 == 'O' && p9 == 'O' || p1 == 'O' && p4 == 'O' && p7 == 'O' || p2 == 'O' && p5 == 'O' && p8 == 'O' || p1 == 'O' && p5 == 'O' && p9 == 'O' || p3 == 'O' && p5 == 'O' && p7 == 'O')
	{ return 0;	}
	else 
	{ return 2; }
}


int main()
{
	//declaring some variables
	char p1, p2, p3, p4, p5, p6, p7, p8, p9;
	p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = '.';
	int choice;
	int userTurn = -1;  //to alternate between x and o turn in playerTurn() function

	printf("Hello, lets play some tic-tac-toe :)");
	printf("\n\n");
	
	int whileExit = 1;

	//starts the loop for the board till someone wins or there's no more open spots on the board
	while (whileExit)
	{
			//display grid using displayFunction()
			displayFunction(p1, p2, p3, p4, p5, p6, p7, p8, p9);

			//check if all spots are occupied, if yes its a tie and use break to terminate program				
			if (tieCheck(p1, p2, p3, p4, p5, p6, p7, p8, p9) == 1) { break; }

			if (winnerIs(p1, p2, p3, p4, p5, p6, p7, p8, p9) == 1) { printf("X has WONN \n"); break; }
			else if (winnerIs(p1, p2, p3, p4, p5, p6, p7, p8, p9) == 0) { printf("O has WONN!\n"); break; }
			

			//decide which player turn it is
			userTurn *= -1;
			int j = playerTurn(userTurn);
		
			//user input here will lbe assign to choice that switch branch will use to assign on the board
			int playerMove = getUserMove();
			while (validatePosition(p1, p2, p3, p4, p5, p6, p7, p8, p9, playerMove) == 0)
			{
				printf("occupied spot \n");		
				playerMove = getUserMove();
			}

			//switch statement recieves which player's turn is it and assigns his spot on the board
				switch (playerMove)
				{
					case 1: if (j > 0) { p1 = 'X'; }else { p1 = 'O'; }
							break;
					case 2: if (j > 0) { p2 = 'X'; }else { p2 = 'O'; }					
							break;
					case 3: if (j > 0) { p3 = 'X'; }else { p3 = 'O'; }					
							break;
					case 4: if (j > 0) { p4 = 'X'; }else { p4 = 'O'; }					
							break;
					case 5: if (j > 0) { p5 = 'X'; }else { p5 = 'O'; }					
							break;
					case 6: if (j > 0) { p6 = 'X'; }else { p6 = 'O'; }					
							break;
					case 7: if (j > 0) { p7 = 'X'; }else { p7 = 'O'; }					
							break;
					case 8: if (j > 0) { p8 = 'X'; }else { p8 = 'O'; }					
							break;
					case 9: if (j > 0) { p9 = 'X'; }else { p9 = 'O'; }				
							break;
					default:
						printf(" -------> ");
						printf("Wrong input... try agian. \n");
						userTurn *= -1;
						break;
				}//end switch statement
			
		}//end while loop	
	

	

	printf("\n");
	return 0;
}

