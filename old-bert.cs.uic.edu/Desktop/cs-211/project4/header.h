/* sample .h file */

/* include all libraries here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* put any #define statements here */
typedef enum status {FALSE = 0, TRUE, NO = 0, YES} boolean;

/* put any structure declarations here */
typedef struct node NODE;
/* list any needed function prototypes here */
//source1.c
void doAdd(NODE** pHead);
void doCallAhead(NODE** pHead);
void doWaiting();
void doRetrieve();
void doList();
void doDisplay(NODE **pHead);

//source2.c
void addToList(pHead);
void displayListInformation(pHead);
boolean updateStatus(NODE** pHead, char* groupName);
void retrieveAndRemove(NODE** pHead, int size);
