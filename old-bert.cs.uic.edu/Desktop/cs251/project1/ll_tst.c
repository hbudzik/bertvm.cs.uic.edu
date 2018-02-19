
#include <stdio.h>
#include <stdlib.h>
#include "llist.c"  //replace with "list.h" for gcc and makefile to work on bertvm

// very incomplete small test program...

int main() {
LIST *lst1;
LIST *lst2;
int i;

  lst1 = lst_create();
  lst2 = lst_create();

  for(i=0; i<5; i++) {
     lst_push_front(lst1, i);
     lst_push_front(lst2, i);
  }
 
  for(i=0; i<5; i++) {
     lst_push_back(lst1, i+3);
  }
  printf("lst_length(lst1) : %i\n", lst_length(lst1));
  printf("lst1 contents: ");
  lst_print(lst1);
  
  printf("lst_length(lst2) : %i\n", lst_length(lst2));
  printf("lst2 contents: ");
  lst_print(lst2);
  
  
  printf("\nlst equal: ");
  if (lst_are_equal(lst1, lst2) == 1)
  {
  	printf("EQUAL");
  }else if(lst_are_equal(lst1, lst2) == 0)
  {
    printf("NOT EQUAL");
  }
  


  //lst_pop_front(lst1);
  //lst_pop_front(lst1);
  //printf("lst1 contents after two pops: ");
  //lst_print(lst1);



  /** TODO:  test code here! **/


  /** test code for lst_count **/
  printf("\n");
  printf("lst1 number of 3's = %i\n", lst_count(lst1, 3));
  printf("lst1 number of 0's = %i\n", lst_count(lst1, 0));


  /** test code for lst_print_rev **/
  printf("\n\n");
  printf("printing lst1 in reverse\n");
  lst_print_rev(lst1);





  /** test code for lst_push_back **/
  
  lst_sanity1(lst2);

  lst_free(lst1);
  lst_free(lst2);
}
  
