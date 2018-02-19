#include <stdio.h>

void computeChange(int totCents, 
				   int* quartersChange, 
                   int* dimesChange, 
                   int* nickelsChange, 
                   int* penniesChange) 
{ 
   
   *quartersChange   = totCents / 25;
   *dimesChange      = (totCents - (*quartersChange * 25)) / 10;
   *nickelsChange    = (totCents - ((*quartersChange * 25) + (*dimesChange * 10))) / 5;
   *penniesChange    = totCents - *quartersChange * 25 + *dimesChange * 10 + *nickelsChange * 5;

}

int main() 
{

   int totalCents     = 67;   // Total amount of change needed
   int quartersChange = 0;    // Number of quarters used for change
   int dimesChange    = 0;    // Number of dimes used for change
   int nickelsChange  = 0;    // Number of nickels used for change
   int penniesChange  = 0;    // Number of pennies used for change

   void computeChange(totalCents, &quartersChange, &dimesChange, &nickelsChange, &penniesChange);

   printf("Change for %d cents is:\n", totalCents);
   printf("  %d quarters\n", quartersChange);
   printf("  %d dimes\n", dimesChange);
   printf("  %d nickels\n", nickelsChange);
   printf("  %d pennies\n", penniesChange);

   return 0;
}
