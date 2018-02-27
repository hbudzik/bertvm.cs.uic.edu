#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

List<int> * arr2list(int a[], int n) {
  List<int> *lst;
  
  lst = new List<int>();

  int i;

  for(i=0; i<n; i++)
      lst->push_back(a[i]);

  return lst;
}

int main(int argc, char *argv[]){
  int arr1[] = {4, 9, 1, 19, 2, 11, 23, 99, 107, -87, -99, 22};
  int arr2[] = {0, 9, 1, 999, 2, 11, 23, 99, 107, -87, 11, 22};
  List<int> *list1;
  List<int> *list2;
  int n1, n2;


  n1 = sizeof(arr1)/sizeof(int);
  n2 = sizeof(arr2)/sizeof(int);

  list1 = arr2list(arr1, n1);
  list2 = arr2list(arr2, n2);

  if( list1->has_dups()  )
    cout << "list1 has dups!\n";
  else 
    cout << "list1 has NO dups!\n";

  if( (*list2).has_dups()  )
    cout << "list2 has dups!\n";
  else 
    cout << "list2 has NO dups!\n";


  return 0;
}
