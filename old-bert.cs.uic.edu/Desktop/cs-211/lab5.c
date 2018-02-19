#include <stdio.h>
#include <stdlib.h>

#define TRUE   1
#define FALSE  0

#define COUNT 10

struct nodeStruct
{
 int elem;
 struct nodeStruct*  next;
};
 
typedef struct nodeStruct node;
typedef node* nodePtr; 

struct listStruct
{
  nodePtr   head;
};

typedef struct listStruct list;

/* prototypes of the functions used in this code  */
/*   also called "forward function declarations" */
int listLength    (node* hd);
int listLengthPBR (node** hd);
int listLength3   (list* lptr);

void show  (node* hd);
void show3 (list* lptr);

void  insertAtFront  (node** hd,  int val);
node* insertAtFront2 (node* hd,   int val);
void  insertAtFront3 (list* lptr, int val);

void  removeFromFront  (node** hd);
node* removeFromFront2 (node* hd);

list init ();
int getFirstValue (node* hd);
int isEmpty (node* hd);

/* written with a pass-by-value parameter */
/* calling code:                          */
/*     node* head = NULL;               */
/*      ...                               */
/*     listLength (head);                 */
int listLength (node* hd)
{
 int length = 0;
 while (hd != NULL)
   {
    length++;
    hd = hd->next;
   }
 return length;
}

/* written with a C-style pass-by-"reference" parameter */
/* calling code:                                d        */
/*     node* head = NULL;                             */
/*      ...                                             */
/*     listLength (&head);                              */
int listLengthPBR (node** hd)
{
 int length = 0;
 while (*hd != NULL)
   {
    length++;
    *hd = (*hd)->next;
   }
 return length;
}


/* written using the structure which encases the head of */
/*  of the list inside the structure.                    */
/* A pointer to the structure is passed to the function  */
int listLength3 (list* lptr)
{
 /* set a temp pointer to the head of the list */
 node* tmp = lptr->head;   

 /* loop through the list counting the number of nodes */
 int length = 0;
 while (tmp != NULL)
   {
    length++;
    tmp = tmp->next;
   }
 return length;
}y


/* the first parameter hd is C-style pass-by-reference */
void insertAtFront (node** hd, int val)
{
 node* ptr = (node*) malloc (sizeof(node));
 ptr->elem = val;
 ptr->next = *hd;       /* note that hd must be "de-referenced" when used */
 *hd = ptr;             /*   the unary * operator is the "de-reference" operator */
}

/* the first parameter, hd, is pass-by-value */
node* insertAtFront2 (node* hd, int val)
{
 node* ptr = (node*) malloc (sizeof(node));
 ptr->elem = val;
 ptr->next = hd;	/* note that had is NOT de-referenced here */
 hd = ptr;
 return hd;
}

/* the head of the list is encased in the struct list */
void insertAtFront3 ( list* lptr, int val)
{
 node* ptr = (node*) malloc (sizeof(node));
 ptr->elem = val;
 ptr->next = lptr->head;   /* access the "head" field from */
 lptr->head = ptr;         /*   the structure pointer      */
}

void removeFromFront (node** hd)
{
 node* ptr = *hd;

 if (ptr != NULL)
   {
    *hd = ptr->next;
    free (ptr);
   }
}

node* removeFromFront2 (node* hd)
{  // code to be written as part of Lab 5, Q. 10
  node* ptr = hd;

 if (ptr != NULL)
   {
    hd = ptr->next;
    free (ptr);







 return hd;
}

int getFirstValue (node* hd)
{
 if (hd != NULL)
   return hd->elem;
 else
   return -999;   /* returns -999 if list is empty */
}

int isEmpty (node* hd)
{
 if (hd == NULL)
   return TRUE;
 else
   return FALSE;
}


void show (node* hd)
{
 while (hd != NULL)
   {
    printf ("%d, ", hd->elem);
    hd = hd->next;
   }
 printf ("\n");
}

/* display the items in a list when the head of the list */
/*   is encased in a stucture                            */
void show3 (list* lptr)
{
 node* tmp = lptr->head;    /* access the head of the list */

 /* loop through the list */
 while (tmp != NULL)
   {
    printf ("%d, ", tmp->elem);
    tmp = tmp->next;
   }
 printf ("\n");
}



/* call a function to intialize the list encased in a structure */
list init ()
{
  list s;
  s.head = NULL;
  return s;
}


int main (int argc, char**argv)
{
  /* two lists declared with just a pointer to a list head */    
  /* initialize the head to null to indicate an empty list */
  node* head = NULL;     
  node* head2 = NULL;

  /* two lists declared using the list struct which contains */
  /*  the pointer to the head inside of the structure        */
  /* initilization head to the list to null in the function  */
  /* This is a better example of data abstraction            */
  list s1 = init();
  list s2 = init();

  int i;
  int temp;

  /* adding values to the front of the list */
  for (i = 0 ; i < COUNT; ++i)
    {
     temp = rand() % 100;
     printf ("In main(): temp: %6d\n", temp);

     /* head being sent as C-style pass-by-reference */
     insertAtFront (&head, temp + 100);		  /* must send the address of head here */

     /* head2 being sent as C pass-by-value */
     head2 = insertAtFront2 (head2, temp + 200);  /* must send the value of head2 here */

     /* use the list "encased" in the structure */
     insertAtFront3 (&s1, temp + 300);

     printf ("List 1 has %d nodes\n", listLength(head));
     show (head);
     printf ("List 2 has %d nodes\n", listLength(head2));
     show (head2);
     printf ("List 3 has %d nodes\n", listLength3(&s1));
     show3 (&s1);
    }

  printf ("\n\nRemoving items from the list\n");
  for (i = 0 ; i < COUNT/2 ; i++)
    {
     int val = getFirstValue (head);
     printf ("The first item in the list is: %d\n", val);
     removeFromFront (&head);

     /* to help show what is going on */
     printf ("The list has %d nodes\n", listLength(head));
     show (head);
    }

  printf ("\n");

  printf ("\n\nRemoving items from the list2\n");
  for (i = 0 ; i < COUNT/2 ; i++)
    {
     int val = getFirstValue (head2);
     printf ("The first item in the list is: %d\n", val);
     head2 = removeFromFront2 (head2);

     /* to help show what is going on */
     printf ("List 2 has %d nodes\n", listLength(head2));
     show (head2);
    }

  printf ("\n");


}

