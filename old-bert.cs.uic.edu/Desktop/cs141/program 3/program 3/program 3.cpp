#include <stdio.h>
#include <ctype.h>
#include <string.h>


void boardDisplay(char boardArray[6][6])
{
	int row = 6;
	int column = 6;
	printf(" 1   1 2 3 4 5 6   2");
	printf("\n");
	printf("     -----------    ");

	char x = 'A';
	int i, j;
	for (j = 0; j < row; j++)
	{
		printf("\n");
		printf(" %c:  ", x);

		for (i = 0; i < column; i++)
		{
			printf("%c ", boardArray[j][i]);
		}
		printf(" :%c", x);
		x++;
	}

	printf("\n");
	printf("     -----------    ");
	printf("\n");
	printf(" 3   1 2 3 4 5 6   4");
	printf("\n");
}


void startingGuide()
{
	printf("\nAuthor: Hubert Budzik");
	printf("\nProgram : #3, Pentago");
	printf("\nTA : Michael Irizarry, Tues 5pm");
	printf("\nFeb 27, 2017");
	printf("\n");
	printf("\nPlay the two - player game of Pentago.Be the first to get 5 in a row.");
	printf("\nPentago is played on a 6 by 6 board, divided into four 3 by 3");
	printf("\nquadrants.There are two players, X and O, who alternate turns.");
	printf("\nThe goal of each player is to get five of their pieces in a row,");
	printf("\neither horizontally, vertically, or diagonally.");
	printf("\n");
	printf("\nPlayers take turns placing one of their pieces into an empty");
	printf("\nspace anywhere on the board, then choosing one of the four");
	printf("\nboard quadrants to rotate 90 degrees left or right.");
	printf("\n");
	printf("\nIf both players get five in a row at the same time, or the");
	printf("\nlast move is played with no five in a row, the game is a tie.");
	printf("\nIf a player makes five a row by placing a piece, there is no need");
	printf("\nto rotate a quadrant and the player wins immediately.");
	printf("\n");
	printf("\nPlay online at : https://perfect-pentago.net");
	printf("\nPurchase at : www.mindtwisterusa.com");
	printf("\n");
	printf("\nFor each move provide four inputs :");
	printf("\nrow(A - F), column(1 - 6), quadrant(1 - 4), rotation direction(L or R)");
	printf("\nFor instance input of B32R places the next piece at B3 and then");
	printf("\nwould rotate quadrant 2 (upper - right) to the right(clockwise).");
	printf("\n");
	printf("\nAt any point enter 'x' to exit the program.");
	printf("\n\n");
}


void setPiece(char boardArray[6][6], int column, int row, char player)
{
	switch (row)
	{
	case 'A':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[0][0] = player; break;
		case 2:	boardArray[0][1] = player; break;
		case 3:	boardArray[0][2] = player; break;
		case 4:	boardArray[0][3] = player; break;
		case 5:	boardArray[0][4] = player; break;
		case 6:	boardArray[0][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	case 'B':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[1][0] = player; break;
		case 2:	boardArray[1][1] = player; break;
		case 3:	boardArray[1][2] = player; break;
		case 4:	boardArray[1][3] = player; break;
		case 5:	boardArray[1][4] = player; break;
		case 6:	boardArray[1][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	case 'C':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[2][0] = player; break;
		case 2:	boardArray[2][1] = player; break;
		case 3:	boardArray[2][2] = player; break;
		case 4:	boardArray[2][3] = player; break;
		case 5:	boardArray[2][4] = player; break;
		case 6:	boardArray[2][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	case 'D':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[3][0] = player; break;
		case 2:	boardArray[3][1] = player; break;
		case 3:	boardArray[3][2] = player; break;
		case 4:	boardArray[3][3] = player; break;
		case 5:	boardArray[3][4] = player; break;
		case 6:	boardArray[3][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	case 'E':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[4][0] = player; break;
		case 2:	boardArray[4][1] = player; break;
		case 3:	boardArray[4][2] = player; break;
		case 4:	boardArray[4][3] = player; break;
		case 5:	boardArray[4][4] = player; break;
		case 6:	boardArray[4][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	case 'F':
		//nested switch 
		switch (column)
		{
		case 1:	boardArray[5][0] = player; break;
		case 2:	boardArray[5][1] = player; break;
		case 3:	boardArray[5][2] = player; break;
		case 4:	boardArray[5][3] = player; break;
		case 5:	boardArray[5][4] = player; break;
		case 6:	boardArray[5][5] = player; break;
		default:  break;
		}//end nested switch 
		break;

	default:  break;
	}//end first switch
}


int checkWinCondition(char boardArray[6][6], char player)
{
	int j; int i;

	//checks for horizontal win
	for (i = 0; i < 6; i++)
	{
		if ((boardArray[i][0] == player && boardArray[i][1] == player && boardArray[i][2] == player && boardArray[i][3] == player && boardArray[i][4] == player)
			|| (boardArray[i][1] == player && boardArray[i][2] == player && boardArray[i][3] == player && boardArray[i][4] == player && boardArray[i][5] == player))
		{
			return 1;
		}
	}//end for loop

	 //checks for vertical win
	for (i = 0; i < 6; i++)
	{
		if ((boardArray[0][i] == player && boardArray[1][i] == player && boardArray[2][i] == player && boardArray[3][i] == player && boardArray[4][i] == player)
			|| (boardArray[1][i] == player && boardArray[2][i] == player && boardArray[3][i] == player && boardArray[4][i] == player && boardArray[5][i] == player))
		{
			return 2;
		}
	}//end for loop

	 //checks for cross win
	for (i = 0; i < 6; i++)
	{
		if ((boardArray[4][0] == player && boardArray[3][1] == player && boardArray[2][2] == player && boardArray[1][3] == player && boardArray[0][4] == player)
			|| (boardArray[5][1] == player && boardArray[4][2] == player && boardArray[3][3] == player && boardArray[2][4] == player && boardArray[1][5] == player)
			|| (boardArray[5][0] == player && boardArray[4][1] == player && boardArray[3][2] == player && boardArray[2][3] == player && boardArray[1][4] == player)
			|| (boardArray[4][1] == player && boardArray[3][2] == player && boardArray[2][3] == player && boardArray[1][4] == player && boardArray[0][5] == player)
			|| (boardArray[1][0] == player && boardArray[2][1] == player && boardArray[3][2] == player && boardArray[4][3] == player && boardArray[5][4] == player)
			|| (boardArray[0][1] == player && boardArray[1][2] == player && boardArray[2][3] == player && boardArray[3][4] == player && boardArray[4][5] == player)
			|| (boardArray[0][0] == player && boardArray[1][1] == player && boardArray[2][2] == player && boardArray[3][3] == player && boardArray[4][4] == player)
			|| (boardArray[1][1] == player && boardArray[2][2] == player && boardArray[3][3] == player && boardArray[4][4] == player && boardArray[5][5] == player))
		{
			return 3;
		}
	}//end for loop
}


void quadrantRotation(char board[6][6], int quadrant, char rotateDirection)
{

	int rowValue, columnValue, j, i;
	char temp;
	if (quadrant == 1) { rowValue = 0; columnValue = 0; }
	if (quadrant == 2) { rowValue = 0; columnValue = 3; }
	if (quadrant == 3) { rowValue = 3; columnValue = 0; }
	if (quadrant == 4) { rowValue = 3; columnValue = 3; }

	if (rotateDirection == 'R')
	{
		//rotate to ther ight
		temp = board[rowValue + 1][columnValue + 0];
		board[rowValue + 1][columnValue + 0] = board[rowValue + 0][columnValue + 1];
		board[rowValue + 0][columnValue + 1] = temp;

		temp = board[rowValue + 2][columnValue + 1];
		board[rowValue + 2][columnValue + 1] = board[rowValue + 1][columnValue + 2];
		board[rowValue + 1][columnValue + 2] = temp;

		temp = board[rowValue + 2][columnValue + 0];
		board[rowValue + 2][columnValue + 0] = board[rowValue + 0][columnValue + 2];
		board[rowValue + 0][columnValue + 2] = temp;

		for (j = 0; j < 3; j++)
		{
			for (i = 0; i < 1; i++)
			{
				temp = board[rowValue + j][columnValue + i];
				board[rowValue + j][columnValue + i] = board[rowValue + j][columnValue + i + 2];
				board[rowValue + j][columnValue + i + 2] = temp;
			}
		}//end of for statemet
	}
	else if (rotateDirection == 'L')
	{
		//rotate to the left	
		temp = board[rowValue + 0][columnValue + 1];
		board[rowValue + 0][columnValue + 1] = board[rowValue + 1][columnValue + 2];
		board[rowValue + 1][columnValue + 2] = temp;

		temp = board[rowValue + 0][columnValue + 0];
		board[rowValue + 0][columnValue + 0] = board[rowValue + 2][columnValue + 2];
		board[rowValue + 2][columnValue + 2] = temp;

		temp = board[rowValue + 1][columnValue + 0];
		board[rowValue + 1][columnValue + 0] = board[rowValue + 2][columnValue + 1];
		board[rowValue + 2][rowValue + 1] = temp;

		for (j = 0; j < 3; j++)
		{
			for (i = 0; i < 1; i++)
			{
				temp = board[rowValue + j][columnValue + i];
				board[rowValue + j][columnValue + i] = board[rowValue + j][columnValue + i + 2];
				board[rowValue + j][columnValue + i + 2] = temp;
			}
		}//end of for statement
	}//end of direction if statement
}


int main()
{		
	//	*initializing board spots and variables
	int		column;					//board's column variable
	char	row;					//board's row variable
	char	player;					//variable to alternate between players 
	int		counter = 1;			//counts how any moves/spots are occupied on the board
	char	boardArray[6][6];		//board array
	int		quadrant;				//variable for selecting quadrants
	char	rotateDirection = 'R';		//indicates which direction to rotate the quadrants( options are L: left, R: right)

	//Assigns initial characters to the board array
	int i, j;
	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < 6; i++)		{ boardArray[j][i] = '.'; }
	}
	
	// this	function will display initial information and rules at the start of the game, 
	startingGuide();	
	
	//starting the loop for the game here, the limit is set to 36 since there are 36 positions on board
	while (counter <=36)
	{
		//this hadles player rotation  
		if		(counter % 2 != 0)	{ player = 'X'; }
		else						{ player = 'O'; }

		//this will display an updated board and add space before and after it is displayed
		printf("\n");
		boardDisplay(boardArray);
		printf("\n");

		//during this loop user input will be validated
		while (counter <= 36)
		{
			//Asks user for input 
			printf("%d. Enter row, column, quadrant, direction for %c: ", counter, player);
			scanf(" %1c", &row);
			scanf(" %1d", &column);
			scanf(" %1d", &quadrant);
			scanf(" %1c", &rotateDirection);

			//Capitalizes input characters
			row = toupper(row);
			rotateDirection = toupper(rotateDirection);

			//checks if selected ROW is valid
			if (column < 1 || column > 6) { printf("*** Invalid move column. Please retry \n"); continue; }
			
			//checks if selected COLUMN is valid
			if (row < 65 || row > 70) { printf("*** Invalid move row. Please retry \n"); continue; }
					
			//checks if positions is occupied
			if (boardArray[row - 65][column - 1] != '.')
			{
				printf("That board location is already taken.  Please retry.\n");
				continue;		//if position is occupied it will print message and retry 
			}

			//checks if selected quadrant is valid
			if (quadrant < 1 || quadrant > 4) {	printf("*** Selected quadrant is invalid. Please retry.\n"); continue;	}

			//this function will assign X or O to the selected spot
			setPiece(boardArray, column, row, player);

			//this function will check if there's a win/tie
			if (checkWinCondition(boardArray, player) == 1) { counter = 36; } //ends game by assigning value to counter that will terminate the lboth while loops
			if (checkWinCondition(boardArray, player) == 2) { counter = 36; } //ends game
			if (checkWinCondition(boardArray, player) == 3) { counter = 36; } //ends game

			break;
		}
		
		//this function will rotate the quadrant after program checks for winning condition
		quadrantRotation(boardArray, quadrant, rotateDirection);

		counter++;		//keeps track of number of moves, once it reaches 36 it will terminate while loops and final board or error message will be printed out 

	}//end of while loop
	
	if (counter == 36 ) {
		printf("its a tie!\n");
		boardDisplay(boardArray);
	}else{
	
	//displays final board and informs who won the game
	printf("%c has won the game!\n\n", player);
	boardDisplay(boardArray);
	printf("\nThanks for playing. Exiting...\n");
	}
	 
return 0;

}//end of main()


