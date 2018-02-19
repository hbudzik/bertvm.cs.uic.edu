/* finalExamDriver.c 
      Starting point code for the in-lab final exam.
      
   Running this program looks like:
		Enter at least five numbers to be used, followed by -1: 1 3 5 7 9 -1
		List is: 9 7 5 3 1
		Third node has 5
		Next-to-last node has 3
		Tail of list has 1
		
		Exiting program
*/

#include <stdio.h>
#include <stdlib.h>   // So sizeof() works

// Declare your struct here, so that the rest of the code works
// ...

typedef struct Node{
	int data;
	struct Node *pNext;
};

//-----------------------------------------------------------------
void displayList(Node *pHead)
{
	// Write code here...
	Node *pTemp = pHead;
	while ( pTemp != NULL) {
		printf("%d ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//-----------------------------------------------------------------
void prependNode( Node *&pHead, Node *&pNextToLast, Node *&pTail, int valueToAdd)
{
	static int nodeCounter = 0;    // Counts how many nodes are created.
				       // Since it is static, its value remains between calls.
	// Get a new node
	Node *pTemp = (Node *) malloc( sizeof(struct Node));
	nodeCounter++;

	// Set the tail pointer if this node is the first one
	if( nodeCounter == 1) {
		pTail = pTemp;
	}
	// Set the nextToLast pointer if this node is the second one to be created
	if( nodeCounter == 2) {
		pNextToLast = pTemp;
	}
	
	// Store values and update pointers
	pTemp->data = valueToAdd;
	pTemp->pNext = pHead;
	pHead = pTemp;	
}

int findAddFunctions( Node *pHead)
{
	int addValues = 0;
	Node *pTemp = pHead;
	while ( pTemp != NULL) {
		if(pTemp->data % 2 != 0){
			addValues++;
		}
		pTemp = pTemp->pNext;
	}
	return addValues;
}



//-----------------------------------------------------------------
int main()
{
	Node *pHead = NULL;
	Node *pThirdNode = NULL;
	Node *pNextToLast = NULL;
	Node *pTail = NULL;

	int userInput = 0;
	printf("Enter at least five numbers to be used, followed by -1: ");
	do {
		scanf("%d", &userInput);
		if( userInput != -1) {
			prependNode( pHead, pNextToLast, pTail, userInput);
		} 	
	} while( userInput != -1);

	printf("List is: ");
	displayList( pHead);
			
	// Set third node pointer, counting from the head of the list.  
	//    This will crash if there aren't at least 3 nodes on the list.
	pThirdNode = pHead->pNext->pNext;
	printf("Third node has %d\n", pThirdNode->data);
	printf("Next-to-last node has %d\n", pNextToLast->data);
	printf("Tail of list has %d\n", pTail->data);

	// adds number to the begginging of list
	Node *pTemp = (Node *) malloc( sizeof(struct Node));
	pTemp = pHead;
	Node *pJunk = (Node *) malloc( sizeof(struct Node));
	
	pJunk->data = 14;
	pJunk->pNext = pTemp;
	pHead = pJunk;
	
	printf("\nafter modification list is: ");
	displayList( pHead);
	// counts odd values
	printf("\nThe number of list values that are odd is %d", findAddFunctions(pHead));

	
	printf("\nExiting program \n");
	return 0;
}// end main()
