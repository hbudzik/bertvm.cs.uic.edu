#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* template code for qsort experiments
*/


int NumComps;


// pre-written function to print elements of an array.
//   might be handy as a sanity check.
void p_array(int a[], int n) {
int i;

  printf("----\n");
  for(i=0; i<n; i++) {
    printf("%i\n", a[i]);
  }
  printf("----\n");
}

/**
* TODO
*   complete this function stub to populate the elements of an array
*   with pseudo-random integers.
*/
void pop_array(int a[], int n) {
int i;

	for(i=0; i<n; i++) 
	    a[i] = rand();
}

int * gen_array(int n) {
int *p;

  p = malloc(n*sizeof(int));
  pop_array(p, n);
  return p;
}

/**
* utility function that might be handy to compute the
*    FLOOR(log_2(n))
*/
int log_2(int n) {
  if(n==1) return 0;
  return 1 + log_2(n/2);
}

/**
* TODO
*
*   Complete "comparator" function to be passed to qsort.
*
*   For this experiment, this function is also "instrumented" to 
*   count the number of times it is called.
*
*   NOTE:  using a global variable for this purpose is OK since
*   it is just a little experiment.
*/
int cmp_int(const void *a, const void *b) {
int *pa, *pb;

  NumComps++;

  pa = (int *)a;
  pb = (int *)b;

  /*
    if(*pa < *pb)
	return -1;
    if(*pa > *pb)
	return 1;
    return 0;
  */
  return (*pa) - (*pb);

}

// comparator function for descending order
int cmp_int_desc(const void *a, const void *b) {
int *pa, *pb;

  NumComps++;

  pa = (int *)a;
  pb = (int *)b;

  return (*pb) - (*pa);
}

int  main(int argc, char **argv) {
int n;

  NumComps=0;
  srand(time(NULL));
  /**
  if(argc > 1)
    n = atoi(argv[1]);
  else
    n = 16;
  **/

  double r_n, r_nlgn, r_n_sq;
  int *data;

  n = 32;

  printf("\n      N       NlogN            N^2           CMPs     N/CMPs      NlogN/CMPs       N^2/CMPs\n");
  printf(" ----------------------------------------------------------------------------------------\n");
  while(n<4000000) {
	  NumComps = 0;
	  data = gen_array( n);

	  qsort(data, n, sizeof(int), cmp_int);

	  free(data);

	  r_n = ((double)n)/NumComps; 
	  r_nlgn = ((double)n*log_2(n))/NumComps; 
	  r_n_sq = ((double)n*n)/NumComps; 

	  printf(" %7i    %8i     %13li    %9i    %6.3f        %6.3f         %6.2f \n", 
			  n, n*log_2(n), (long)n*n, NumComps, r_n, r_nlgn, r_n_sq);

	  n *= 2;
  }

  /** TODO
	Complete code to run an experiment which does the following:

	  - populates array data[] with pseudo-random values
	  - initializes a variable which counts the number of comparisons
		made (probably a global).
	  - calls the qsort library function on the data[] array using
		the comparator function you wrote above.
	  - produces a report printing the following:

		o Number of comparisons qsort made
		o n^2
		o log_2(n)
		o n*log_2(n)
  */ 

}
