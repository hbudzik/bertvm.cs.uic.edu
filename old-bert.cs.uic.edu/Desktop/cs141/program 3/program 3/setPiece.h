//this function will assign X or O into a selected spot

void setPiece(char boardArray[6][6], int boardNumber, int boardCharacter, char player)
{
	

	
		switch (boardCharacter)
		{
		case 'A':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[0][0] = player; break;
			case 2:	boardArray[0][1] = player; break;
			case 3:	boardArray[0][2] = player; break;
			case 4:	boardArray[0][3] = player; break;
			case 5:	boardArray[0][4] = player; break;
			case 6:	boardArray[0][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		case 'B':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[1][0] = player; break;
			case 2:	boardArray[1][1] = player; break;
			case 3:	boardArray[1][2] = player; break;
			case 4:	boardArray[1][3] = player; break;
			case 5:	boardArray[1][4] = player; break;
			case 6:	boardArray[1][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		case 'C':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[2][0] = player; break;
			case 2:	boardArray[2][1] = player; break;
			case 3:	boardArray[2][2] = player; break;
			case 4:	boardArray[2][3] = player; break;
			case 5:	boardArray[2][4] = player; break;
			case 6:	boardArray[2][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		case 'D':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[3][0] = player; break;
			case 2:	boardArray[3][1] = player; break;
			case 3:	boardArray[3][2] = player; break;
			case 4:	boardArray[3][3] = player; break;
			case 5:	boardArray[3][4] = player; break;
			case 6:	boardArray[3][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		case 'E':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[4][0] = player; break;
			case 2:	boardArray[4][1] = player; break;
			case 3:	boardArray[4][2] = player; break;
			case 4:	boardArray[4][3] = player; break;
			case 5:	boardArray[4][4] = player; break;
			case 6:	boardArray[4][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		case 'F':
			//nested switch 
			switch (boardNumber)
			{
			case 1:	boardArray[5][0] = player; break;
			case 2:	boardArray[5][1] = player; break;
			case 3:	boardArray[5][2] = player; break;
			case 4:	boardArray[5][3] = player; break;
			case 5:	boardArray[5][4] = player; break;
			case 6:	boardArray[5][5] = player; break;
			default: printf("*** Invalid move column. Please retry \n"); break;
			}//end nested switch 
			break;

		default: printf("*** Invalid move row. Please retry \n");
			break;
		}//end first switch
	
}
