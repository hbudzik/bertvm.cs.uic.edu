#include "Stack.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

// using namespace std;


int main(int argc, char *argv[]){
  Stack<int> *stk;
  clock_t start, end, diff;
  int i, t;
  int n = 100;
  int ntrials = 1000;


  if(argc>=2)
    n = atoi(argv[1]);
  if(argc==3)
    ntrials = atoi(argv[2]);

  start = clock();
  for(t=0; t<ntrials; t++) {
    Stack<int> *stk = new Stack<int>(true);
    for(i=0; i<n; i++) {
      stk->push(i);
    } 
    delete stk;
  }
  end = clock();
  diff = end - start;

  std::cout << "N=" << n << " ; TIME FOR DOUBLING POLICY: " << diff << "\n";

  start = clock();
  for(t=0; t<ntrials; t++) {
    Stack<int> *stk = new Stack<int>(false);
    for(i=0; i<n; i++) {
      stk->push(i);
    } 
    delete stk;
  }
  end = clock();
  diff = end - start;

  std::cout << "N=" << n << " ; TIME FOR ADDITIVE POLICY: " << diff << "\n";

  return 0;
}
