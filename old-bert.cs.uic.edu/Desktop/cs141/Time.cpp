#include <stdio.h>

typedef struct TimeHrMin_struct {
   int hrVal;
   int minVal;
} TimeHrMin;

TimeHrMin ConvHrMin(int totTime) {
   TimeHrMin timeStr;
   timeStr.hrVal  = totTime / 60;
   timeStr.minVal = totTime % 60;
   return timeStr;
}

int main(void) {
   int inTime = 0;
   TimeHrMin timeStr1;

   printf("Enter tot minutes: ");
   scanf("%d", &inTime);
   timeStr1 = ConvHrMin(inTime);
   printf("Equals: ");
   printf("%d hrs ", timeStr1.hrVal);
   printf("%d mins\n", timeStr1.minVal);
   getchar();
   getchar();
   return 0;
}
