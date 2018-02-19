#include "header.h"

typedef struct node
{
	char *groupName;
	int groupSize;
	boolean status;
	struct node* next;
} NODE;

//adds client to the list as in restaurant 
void addToList(NODE** pHead, char *groupName, int groupSize, boolean inRestStat)
{
	NODE *newNode = (struct node*) malloc(sizeof(NODE));
	NODE *q = *pHead;	//we will use this to traverse the linked list 
	
	// put in data inside the new node
	newNode->groupName = (char *) malloc(sizeof(char) * strlen(groupName));
	strcpy( newNode->groupName, groupName);
	newNode->groupSize = groupSize;
	
	//marks that client is waiting in restaurant 
	newNode->status = inRestStat;
	
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


//updates status of a group from call-ahead to in-restaurant
boolean updateStatus(NODE** pHead, char* groupName)
{
	//will traverse the linked list until given name is found
	NODE *tmp = *pHead;
	
	//will move through the list untill NULL is reached or groupName is found
	while(tmp->next != NULL && strcmp(tmp->groupName, groupName) != 0 )
	{
		tmp = tmp->next;		
	}
	if (strcmp(tmp->groupName, groupName) == 0)
	{
		if(tmp->status == YES)
			{
				printf("\nError... this group is already in restaurant");
				return FALSE;
			}
		tmp->status = YES;
		return TRUE;
	}
	printf("\n name not found...\n");
	return FALSE;
}


//* This function will remove a node 
void retrieveAndRemove(NODE** pHead, int requestSize)
{
	NODE* temp = *pHead;	//for traversing the list
	NODE* prev = *pHead;	//for linking list after deletion
	
	//will traverse the list untill we find node corresponding with the table size asked
	while (temp->next != NULL && temp->groupSize > requestSize)
	{
		prev = temp;
		temp = temp->next;
	}
	
	//if we found a group with less or equal seats as requested we can remove it from the queue
	if(temp->groupSize <= requestSize)
	{
		if (pHead == temp)
		{
		//if pHead itself need to be deleted
		pHead = temp->next;		//make second node as head
		free(temp);					//free first node(delete it)
		}else{
			prev->next = temp->next;	//jump over a node 
			free(temp);					//free the jumped node
		}
		return;
	}
	
	//
	
	
	return;
}


//*	displays entire queue in order from first in line to the last
void displayListInformation(NODE** pHead)
{
	NODE *temp = *pHead;	//creates new head pointer that will be used to traverse throught the list
	int counter = 1; 		//counts nodes 
	printf("\n***	printing all the nodes front to back:	***\n\n");
	

	while(temp != NULL)
	{
		printf(	"Number %d in line\n", counter	);
		printf(	"Group name: %s	\n", temp->groupName	);
		printf(	"Group size: %d	\n", temp->groupSize	);
		printf( "In restaurant status: %d", temp->status);
		
		printf("\n\n");
		counter++;
		
		temp = temp->next;
	}	
}

