#include <stdio.h>
#include <stdlib.h>	//needed for malloc

struct Node{
	int data;
	struct Node *pNext;
};

//places new value at the end of the list
void appendList(struct Node **pHead, int newData)
{
	
	//1. allocating memory for new list
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	struct Node *tmp = *pHead;
	
	//2. put new data
	newNode->data = newData;
	
	//3. since this is going to be last node we mush point it to null
	newNode->pNext = NULL;
	
	
	
	//4. if list is empty than make pHead point to newNode
	
	if (*pHead == NULL)
	{
		
	
		*pHead = newNode;
		
		return;
	}
	
	//5. else traverse till the last one
	while(tmp->pNext != NULL)	
	{
		tmp = tmp->pNext;
	}
	
	//6. assign newNode where NULL was, newNode now points to NULL step 3 
	tmp->pNext = newNode;
	return;
}


void displayNodes(struct Node *pHead)
{
	int count;
	printf("List: ");
	while(pHead != NULL)
	{
		
		printf(" %d ", pHead->data);
	
		pHead = pHead->pNext;
		
    }
}


int main()
{
	
	
	struct Node *pHead = NULL;
	
	appendList(&pHead, 5);
	appendList(&pHead, 10);
	appendList(&pHead, 15);
	

    
    
	displayNodes(pHead);


	return 0;
}

