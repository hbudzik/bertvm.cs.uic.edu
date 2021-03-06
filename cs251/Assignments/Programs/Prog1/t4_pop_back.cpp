#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>

#include "_test.h"
#include "_util.h"

int arrs[][5] = {
		{ 1, 2, 3, 4, 5} ,
		{ 5, 4, 3, 2, 1},
		{ 0, 2, 3, 4, 5} ,
		{ 1, 2, 3, 4, 0} ,
		{ 0, 0, 0, 0, 0} ,   //IDX-4
		{ 1, 0, 0, 0, 0} ,   //IDX-5
		{ 0, 0, 0, 0, 1},    //IDX-6
		{ 0, 1, 0, 1, 0}     //IDX-7
	     };

using namespace std;

bool testA() {
  int popped;
  bool result=true;


	  lsts[0] = arr2list(arrs[0], 5);
	  if(!lsts[0]->pop_back(popped) || popped != 5) 
      result = false;

    cleanup();
    return result;
}


int main(int argc, char *argv[]){
  int n = __N;
  int ntrials = __NTRIALS;
  int i, dummy;

  if(argc > 1)
    n = atoi(argv[1]);
  if(argc > 2)
    ntrials = atoi(argv[2]);

  set_ntrials(ntrials);

  printf("STARTING AUTO-TEST WITH: \n");
  printf("    N (Big Problem Size) = %i\n", n);
  printf("    NUM_TRIALS       = %i\n", ntrials);
  printf("USAGE TO OVER-RIDE DEFAULT N and NUM_TRIALS:\n");
  printf("    %s <N> <NUM_TRIALS>\n\n", argv[0]);
  printf("EXAMPLE WITH N=9999; NUM_TRIALS=100000:\n");
  printf("    %s 9999 100000\n\n", argv[0]);

  printf("here we go...\n\n");

  START("List::pop_back PARTIAL test Suite (9/15 pts)"); 
  {
	  PtsPer = 3.0;
	  lsts[0] = arr2list(arrs[0], 5);

	  TEST_RET(testA(), "simple pop_back", true, PtsPer);
	  cleanup();
	
	  lsts[0] = arr2list(arrs[0], 5);
	  lsts[0]->pop_back(dummy);

	  TEST_RET(eq2array(lsts[0], arrs[0], 4), 
			"test list after pop_back([1 2 3 4 5])", 
			1, PtsPer);
    cleanup();

	  
	  lsts[0] = arr2list(arrs[0], 5);
	  lsts[1] = arr2list(arrs[0], 4);
	
	  lsts[1]->push_back( 99);
	  lsts[0]->pop_back(dummy);
	  lsts[0]->push_back(99);

	  TEST_RET(lsts_equal_destructive(lsts[0], lsts[1]), 
		"pop_back followed by push_back test", 
		true, PtsPer);

  }
  END







  printf("\n\nPOST-MORTEM...\n");
  printf("YOU JUST RAN THIS AUTO-TEST WITH: \n");
  printf("    N (Big Problem Size) = %i\n", n);
  printf("    NUM_TRIALS       = %i\n\n", ntrials);
  printf("IF YOU RECEIVED A ");
  _red_txt();
  printf("WARNING ");
  _normal_txt();
  printf(" ABOUT UNRELIABLE RUNTIEM MEASUREMENTS\n");
  printf("AND INCREASING NUMBER OF TRIALS / PROBLEM SIZE\n");
  printf("HERE IS HOW YOU DO IT:\n\n");
  printf("  USAGE TO OVER-RIDE DEFAULT N and NUM_TRIALS:\n");


  _cyan_txt();
  printf("    %s <N> <NUM_TRIALS>\n\n", argv[0]);
  _normal_txt();
  printf("  EXAMPLE WITH N=9999; NUM_TRIALS=100000:\n");
  _cyan_txt();
  printf("    %s 9999 100000\n\n", argv[0]);
  _normal_txt();

  cleanup();

  return 0;
}
