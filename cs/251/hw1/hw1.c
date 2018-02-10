#include <stdio.h>
#include <stdlib.h>			/* malloc, free, rand */

struct NODE{
	int data;
	int inUse;
	struct NODE *next;	
};

//here we will initialise our list 
void nodeInit(struct NODE *LIST)
{
	LIST = (struct NODE *) malloc(sizeof(struct NODE));
	LIST->next = NULL;
}


// will print the content of the linked list 
void printLIST(struct NODE* LIST)
{
	//checks if list is empty 
	while (LIST != NULL)
	{
		//prints NODE info
		printf("inUse: %d \n", &LIST->inUse);
		printf("data: %d \n", &LIST->data);
		
		
		//moves up a NODE
		LIST = LIST->next;
		
	}
	printf("NULL REACHED \n");
	return;
}



int main()
{	
	struct NODE *LIST;
	
	//initializes the list 
	nodeInit(LIST);
	printf("\n out of nodeInit(LIST)\n");
	
	//prints the list
	printLIST(LIST);
	
	printf("\n back in main exiting... \n");
	

	
	
	printf("Hey\n");
	
	return 0;
	
}
