//this function displays updated board

void boardDisplay(char boardArray[6][6])
{
	int row		= 6;
	int column	= 6;
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