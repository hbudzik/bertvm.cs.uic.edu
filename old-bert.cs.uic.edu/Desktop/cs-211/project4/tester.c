#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
	char *groupName;
	int groupSize;
	struct node* next;
} NODE;

void addToList(NODE** pHead, char *groupName, int groupSize)
{
	NODE *newNode = (struct node*) malloc(sizeof(NODE));
	NODE *q = *pHead;	//we will use this to traverse the linked list 
	
	// put in data inside the new node
	newNode->groupName = malloc(sizeof(char) * strlen(groupName));	//allocates enought memory 
	strcpy( newNode->groupName, groupName);
	newNode->groupSize = groupSize;
	
	// this is going to be a last node so we set newNode->next to NULL
	newNode->next = NULL;
	
	// if linked list is empty 
	if (*pHead == NULL)
	{
		*pHead = newNode;
		return;
	}
	
	// if there already exist a NODE in a queue than traverse the list till you reach the last node 
	while(q->next != NULL)
	{
		q = q->next;
	}
	
	// add node to the end of the list
	q->next = newNode;
		
}

int main()
{
	NODE * pHead = NULL ;
	
	char *name = "hubert";
	int size = 5;

	

	
	
	
	addToList(&pHead, name, size);
	printf("node name : %s", pHead->groupName);

	
	
}
