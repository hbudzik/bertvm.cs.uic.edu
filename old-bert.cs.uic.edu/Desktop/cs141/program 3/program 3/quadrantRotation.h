
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