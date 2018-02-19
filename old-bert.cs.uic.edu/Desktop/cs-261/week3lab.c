#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CMP_COUNT = 0;
/**
* template code for qsort experiments
*/



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

  // your code here
int i = 0;
for (i=0; i < n; i++)
	a[i] = rand();
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

  // YOUR CODE HERE
}

int  main(int argc, char **argv) {
int n;


  srand(time(NULL));
  if(argc > 1)
    n = atoi(argv[1]);
  else
    n = 16;

  int data[n];
  pop_array(data, n);
  
  // prints pop_array after its called
  int i;
  for (i=0; i<n; i++)
  printf("%i\n", data[i]);
  

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
