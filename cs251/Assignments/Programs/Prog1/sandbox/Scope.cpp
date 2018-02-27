#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>

/**
 * simple program "proving" that destructors are
 *   automatically invoked on objects/instances 
 *   when they go out of scope.
 *
 * This is NOT the case for object/instance POINTERS
 *
 * The destructor ~List in this directory has been modified
 *   to print a short message.
 *
 * The output of the program when run demonstrates the sequence
 *   in which things happen.
 */

using namespace std;

void foo(){
  List<int> tst;

  tst.push_front(99);
  tst.push_front(111);
  tst.push_front(222);
  tst.print();

  // notice that we do not delete tst

  cout << "last line of foo()\n";
}

int main(int argc, char *argv[]){

  foo();
  cout << "main:  first line after call to foo()\n";

  return 0;
}
