

int checkWinCondition(char boardArray[6][6], char player)
{
	int j; int i; 
	
	//checks for horizontal win
	for (i = 0; i < 6; i++)
	{
		if ((boardArray[i][0] == player && boardArray[i][1] == player && boardArray[i][2] == player && boardArray[i][3] == player && boardArray[i][4] == player) 
			|| (boardArray[i][1] == player && boardArray[i][2] == player && boardArray[i][3] == player && boardArray[i][4] == player && boardArray[i][5] == player))
		{ return 1; }
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
						||	(boardArray[1][0] == player && boardArray[2][1] == player && boardArray[3][2] == player && boardArray[4][3] == player && boardArray[5][4] == player)
							|| (boardArray[0][1] == player && boardArray[1][2] == player && boardArray[2][3] == player && boardArray[3][4] == player && boardArray[4][5] == player)
								|| (boardArray[0][0] == player && boardArray[1][1] == player && boardArray[2][2] == player && boardArray[3][3] == player && boardArray[4][4] == player)
									|| (boardArray[1][1] == player && boardArray[2][2] == player && boardArray[3][3] == player && boardArray[4][4] == player && boardArray[5][5] == player))
		{
			return 3;
		}
	}//end for loop

}