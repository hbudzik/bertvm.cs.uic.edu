//#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>

/**
#include "_test.h"
#include "_util.h"
**/

using namespace std;



void clk_tst() {
  int i=0;
  double x, y;
  clock_t start, end;

  x = 2.7;
  y = 1.3;

  start = clock();
  do{
    x = 2*x / y;
    y = y - x;
    i++;
    end = clock();
  }
  while(end==start);

  clock_t UnitsPerTick = end-start;

  printf("UnitsPerTick: %lu\n", UnitsPerTick);
  printf("Iterations:   %i\n", i);
}

int main(int argc, char *argv[]){
  clk_tst();


  return 0;
}
