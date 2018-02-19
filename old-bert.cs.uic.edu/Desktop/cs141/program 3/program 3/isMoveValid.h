
int isMoveValid(char boardArray[6][6], char row, int column)
{
	
	if		(boardArray[row-65][column] == '.')	{ return 0; }
	else											{ return 1; }

}