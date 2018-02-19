/* This file contains the user interface code for the Infix Evaluation Project
 *  Project 5 for CS 211 for Fall 2017
 *
 * Date: 10/21/17
 *
 * Author: Pat Troy
 *
 */

#include "proj5Tokens.h"
 bool debuggmode = true;
//this will evaluate arithmetic expressions using values from value stacka nd operator from operator stack
void popAndEval(Darray *stack1, Darray *stack2)
{
	int op = stack2->top();
	stack2->pop();
	int val2 = stack1->top();
	stack1->pop();
	int val1 = stack1->top();
	stack1->pop();
	int val3;
	if (op == '-'){
		val3 = val1 - val2;
	}else if (op == '+'){
		val3 = val1 + val2;
	}else if (op == '*'){
		val3 = val1 * val2;
	}else if (op == '/'){
		val3 = val1 / val2;
	}
	stack1->push(val3);
}

void printCommands();

void processExpression (Token inputToken, TokenReader *tr);

int main(int argc, char *argv[])
{
    /***************************************************************/
    /* Add code for checking command line arguments for debug mode */
    
 
  if (argc > 1 && strcmp(argv[1], "-d")==0)
  {
    debuggmode = true;
  }

    Token inputToken;
    TokenReader tr;

    printf ("Starting Expression Evaluation Program\n\n");
    printf ("Enter Expression: ");

    inputToken = tr.getNextToken ();

    while (inputToken.equalsType(QUIT) == false)
    {
      /* check first Token on Line of input */
      if(inputToken.equalsType(HELP))
      {
       printCommands();
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(ERROR))
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(EOLN))
      {
       printf ("Blank Line - Do Nothing\n");
       /* blank line - do nothing */
      }
      else
      {
       processExpression(inputToken, &tr);
      }

      printf ("\nEnter Expression: ");
      inputToken = tr.getNextToken ();
    }

  printf ("Quitting Program\n");
  return 1;
}

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}


void processExpression (Token inputToken, TokenReader *tr)
{
 /**********************************************/
 /* Declare both stack head pointers here      */
	Darray stack1;			//values stack
	Darray stack2;			//operator stack
	
 /* Loop until the expression reaches its End */
 while (inputToken.equalsType(EOLN) == false)
   {
    /* The expression contain a VALUE */
    if (inputToken.equalsType(VALUE))
      {
       /* make this a debugMode statement */
       if (debuggmode == true)
      		printf ("Val: %d, ", inputToken.getValue() );
       
       // add code to perform this operation here
		stack1.push( inputToken.getValue() );		
      }

    /* The expression contains an OPERATOR */
    else if (inputToken.equalsType(OPERATOR))
      {
	   /* make this a debugMode statement */
       if (debuggmode == true)
	   		printf ("OP: %c, ", inputToken.getOperator() );

       // add code to perform this operation here
       
       //checks for open parenthesis and pushes them onto the operator stack
       if (inputToken.getOperator() == '(')
		{
			stack2.push(inputToken.getOperator());
		}//end if
       
       //evaluates '+' and '-'
		if (inputToken.getOperator() == '+' || inputToken.getOperator() == '-')
		{
		
			while (stack2.isEmpty() == false && ( stack2.top() == '+' || stack2.top() == '-' || stack2.top() == '*' || stack2.top() == '/'))
			{
				popAndEval(&stack1, &stack2);		
			}
			stack2.push(inputToken.getOperator());
		}//end of '+' and '-' eval
			
		//evaluates '*' and '/'
		if (inputToken.getOperator() == '*' || inputToken.getOperator() == '/')
		{
		
			while (stack2.isEmpty() == false && ( stack2.top() == '*' || stack2.top() == '/'))
			{
				
				popAndEval(&stack1, &stack2);		
			}
			stack2.push(inputToken.getOperator());
		}//end of '*' and '/' eval	
      
      //checks for closed parenthesis and evaluates whats in it
      if (inputToken.getOperator() == ')')
		{
			while (stack2.isEmpty() == false &&  stack2.top() != '(')
			{
				popAndEval(&stack1, &stack2);	
			}
			stack2.pop();		//pops the open paranthesis
	 	}/*
	 	
		if (stack2.isEmpty() == true)
		{
			printf("\nERROR !!!");
		}
		else
		{
			stack2.pop();		pops the open paranthesis
		}*/
      //	done evaluating parenthesis 
	  }

    /* get next token from input */
    inputToken = tr->getNextToken ();
   }
  

 /* The expression has reached its end */
 

 // add code to perform this operation here
while (stack2.isEmpty() == false)
{
	popAndEval(&stack1, &stack2);
}

printf("\nFinal value: %d", stack1.top());

 printf ("\n");
}

