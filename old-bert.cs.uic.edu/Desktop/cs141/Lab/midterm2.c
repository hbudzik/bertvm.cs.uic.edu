#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char phrase[] = "co jest stara palko";
	char phrase2D[4][20];
	char *pSpace = NULL;
	char *pCurrent = NULL;
	int length;
/*	
	fprintf(stdout,"Original 1D phrase: %s\n", phrase);
	pSpace = strchr(phrase, ' ');
	length = pSpace - phrase;
	fprintf(stdout, "Number of characters: %d\n", length);
	
	strncpy(phrase2D[0], phrase, length);
	fprintf(stdout, "First word cut out from original pharase: %s\n", phrase2D[0]);
	
	pCurrent = pSpace + 1;
	//finding second space position
	pSpace = strchr(pCurrent, ' ');
	length = pSpace - pCurrent;
	fprintf(stdout, "Number of characters: %d\n", length);
	
	strncpy(phrase2D[1], pCurrent, length);
	fprintf(stdout, "Second word cut out from original pharase: %s\n", phrase2D[1]);
	*/
	//here we weill extract these strings using sscanf
	sscanf(phrase, "%s %s %s", phrase2D[0], phrase2D[1], phrase2D[2]);
	//sprintf(phrase, "hello");
	
	fprintf(stdout, "%s\n", phrase);
	phrase2D[3] = strstr(phrase, );
	
	fprintf(stdout, "[0]: %s. [1]: %s. [2]: %s. [3]: %s.", phrase2D[0], phrase2D[1], phrase2D[2], phrase2D[3]);
	

	
//	fprintf("%s", phrase2D);
	
	
	
	
	return 0;	
}
