//author: 	Hubert Budzik
//UID: 	  	hbudzi2

//project 2
//proffessor: 	Patrick Troy
//course: 		cs211

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


/* typical C boolean set-up */
#define TRUE 1
#define FALSE 0


typedef struct StackStruct
{
 char*    darr;  /* pointer to dynamic array  */
 int     size;  /* amount of space allocated */
 int     inUse; /* top of stack indicator 
		   - counts how many values are on the stack   */
} Stack;


//	initializing the stack
void init (Stack* s)
{
 s->size = 2;
 s->darr = (char*) malloc ( sizeof (char) * s->size );
 s->inUse  = 0;
}


int isEmpty (Stack* s)
{
  if ( s->inUse == 0)
    return TRUE;
  else
    return FALSE;
}


void push (Stack* s, char val)
{
  /* check if enough space currently on stack and grow if needed */
 
  if (s->size == s->inUse)
	{	
		Stack temp;
		temp.darr = (char *) malloc (sizeof(char) * s->size + 2);
		int i;
		for (i=0; i < s->size; i++)
		{
		  temp.darr[i] = s->darr[i]; 
		}
		
		free(s->darr);
		s->darr = temp.darr;
		s->size = s->size + 2;
	}

  /* add val onto stack */
  s->darr[s->inUse] = val;
  s->inUse = s->inUse + 1;
}


int top (Stack* s)
{
  return (  s->darr[s->inUse-1] );
}


void pop (Stack* s)
{
  s->inUse = s->inUse - 1;
}

	
void stk1Debugg(Stack* s)
{
	printf("\n--->>>  Running stack debugg");
	printf ("								\n"
			"STACK:							\n"
			"		-Size:>  %d				\n"
			"		-inUse:> %d				\n"
			, s->size, s->inUse);
	
	//printing whats on the stack atm
	int z;
		printf("printing stack:> ");
	for (z = 0; z < s->inUse; z++)
		{
		
			printf("%c", s->darr[z]);
		}
}


int main(int argc, char** argv)
{
  //checking for debugging mode
  int debuggmode = FALSE;
  if (argc > 1 && strcmp(argv[1], "-d")==0)
  {
    debuggmode = TRUE;
  }
  
  //creating stack and initializing it
  Stack stk1;
  init ( &stk1);
  int x = 0;

  //taking user input and storing it in a array
  printf("Enter a string of characters\n");
  char arrayIn[301];
  fgets(arrayIn, 300, stdin);
  
  //checking if input is q or Q, if true quits the program
  if (strcmp(arrayIn, "q\n") == 0 || strcmp(arrayIn, "Q\n") == 0)
  {
  	printf("quitting\n");
    return 0;
  }
  
  //debugging new array
 // arrayDebug(arrayIn);
  
  //running while loop that manipulates the stack
  int z=0 ;		//moves through an array
  int i = 1;	//counts which position we are in an array
  while (arrayIn[z] != '\n')
  {
  	//breakes off if element is not one of elements
	if (!(arrayIn[z] == '(' || arrayIn[z] == '[' || arrayIn[z] == '{' || arrayIn[z] == '<' || arrayIn[z] == ')' || arrayIn[z] == ']' || arrayIn[z] == '}' || arrayIn[z] == '>' ))
  	{
  		z++;
  		i++;
  		continue;
	  }
  	
  	//checking for open symbols and placing them on the stack
  	if(arrayIn[z] == '(' || arrayIn[z] == '[' || arrayIn[z] == '{' || arrayIn[z] == '<' )
  	{
  	 if (debuggmode == TRUE)
  	  	{
  	  		printf("pushing on the stack %c\n", arrayIn[z]);
		}
		
  	  push(&stk1, arrayIn[z]); 
  	  i++;
  	  z++;
  	  continue;
    }
    
	if(isEmpty(&stk1) == FALSE )
	{	
	  	//checking for closed symbols and popping them off the stack
	  	if(arrayIn[z] == ')' || arrayIn[z] == ']' || arrayIn[z] == '}' || arrayIn[z] == '>' )
	  	{
	  	  
	  	  //EXPECTING
	  	  //compare with whats on the top of the stack and pop off corresponding symbol
	  	  	if (top(&stk1) == arrayIn[z]-2 || top(&stk1) == arrayIn[z]-1)
			{
			if (debuggmode == TRUE)
  	  		{
  	  		printf("popping off the stack %c\n", top(&stk1));
			}
			
			  pop(&stk1);
			  i++;
			  z++;
			  continue;
			}
			else //checks if stack is empty and throws which symbol is exp
			{
				int n;
				for (n=1; n < i; n++)
				{
				  	printf(" ");
				}	
				  
					if  (arrayIn[z] == ')')
					{ 
					    printf("^ EXPECTING %c\n", arrayIn[z]-1);
					    return 0;
					}
				  	else
				  	{	
					  	printf("^ EXPECTING %c\n", arrayIn[z]-2);
					  	
					  	return 0;
				  	} 
			} 
			//end EXPECTING loop
		}//end if loop
	}
	else
	{
		
		    //MISSING
		    //compares, if stack empty and more symbols are closing throws an error
		  
		  	
		  	  //checking if there are any symbols left in an array
		  	  if (arrayIn[z] == ')' || arrayIn[z] == ']' || arrayIn[z] == '}' || arrayIn[z] == '>' )
				{
				      int n;
					  for (n=1; n < i; n++)
					  {
					  	printf(" ");
					  }	
					  	  if(arrayIn[z] == ')')
						  {
						    printf("^ MISSING %c\n", arrayIn[z]-1);
						    x = 1;
						    return 0;
						  }else{
						  	printf("^ MISSING %c\n", arrayIn[z]-2);
						  	x = 1;
						  	return 0;
						  }
				}//end test for any symbols left loop
	}
}//end while
  
  
  //checking if expression is balanced
  if (isEmpty(&stk1) == TRUE )
 	
  		{
  			printf("EXPRESSION IS BALANCED");
		}
  
  //checks if theres still stuff on the stack
  	if (isEmpty(&stk1) == FALSE)
 	{
  				int n;
				for (n=1; n < i; n++)
				{
				  	printf(" ");
				}	
				  
					if  (top(&stk1) == '(')
					{ 
					    printf("^ MISSINGd %c", top(&stk1)+1);
					}
				  	else
				  	{	
					  	printf("^ MISSINGd %c", top(&stk1)+2);
				  	} 
	}
  
  //stk1Debugg(&stk1);
  printf("\ni: %d\n", i);
  
	return 0;
}



