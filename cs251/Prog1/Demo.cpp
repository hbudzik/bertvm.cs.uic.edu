#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>  //for srand seed

using namespace std;

List<int> * slow_list(int n) {

  // placeholder
  return nullptr;
}

int main(int argc, char *argv[]){
  List<int> *list = new List<int>();
  List<string> *list2 = new List<string>();
  List<string> *list3 = new List<string>();
  
  //test lists
  List<int> * listTest2 = new List<int>();
  listTest2->push_front(9);
  listTest2->push_front(7);
  listTest2->push_front(5);
  listTest2->push_front(3);
  listTest2->push_front(1);


  List<string> *testList = new List<string>();
  testList->push_front("xx");
  testList->push_back("yy");
  testList->push_back("zz");




  int x;
  int n, ndel;

  n = 1000;

  if(argc == 2) {
    n = atoi(argv[1]);
  }

  srand(time(0));   // for random rand()

    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);
    list->push_front(rand() % 5 +1);

  list->print();

  for(x=1; x<=4; x++) {
    list->push_back(x);
  }

  list->print();

  list->pop_front(x);
  cout << "popped " << x <<endl;
  list->print();

  list->slow_remove_all(2);
  cout << "after remove-all(2):\n";
  list->print();

  // string words[] = {"hello", "goodbye", "sunrise", "sunset"};
  string words[] = {"aa", "bb", "cc", "dd"};


  for(int i=0; i<4; i++) {
      list2->push_front(words[i]);
      list3->push_back(words[i]);
  }

  cout << endl << "print list2 now:\t";
  list2->print();
  cout << "print list2 reverse\t";
  list3->print();

  cout << "list  sorted?  " << list->is_sorted() << endl;
  cout << "list2 sorted?  " << list2->is_sorted() << endl;
  cout << "list3 sorted?  " << list3->is_sorted() << endl;


  //will count number of occurences of x in nodes in each list
  cout << "List has this mandy 1s:\t";
  list->count(1);
  cout << "list2 has this many aa:\t";
  list2->count("aa");
  cout << "list3 has this many bb:\t"; 
  list3->count("bb");

  //will check if two lists are equal, equal_to() function
  list->equal_to(*list);
  list2->equal_to(*list3);

  //popping back NODE 
  int newData;
  cout << endl << "popping back NODE: pop_back " << endl;
  cout << "current list: ";
  list->print();
  
  if (list->pop_back(newData) == true){
    cout << "removed back node" << endl;
    cout << "data stored: " << newData << endl;
  }else{
    cout << "remove did not happen" << endl;
  }
  cout << "list after popped value: " << endl; 
  list->print();
  
  //printing in reverse recursively 
  cout << endl << "Printing list in reverse RECURSIVLY!" << endl;
  list->print_rev();
 

  //here will reverse the list print it without assigning new memory 
  cout << endl << "PRINTING LIST original: " << endl;
  list->print();
  cout << endl << "PRINTING LIST AFTER reverse() FUNCT, reversing the list" << endl;
  list->reverse();
  list->print();
  
  // fast_remove_all(x);
  cout << "TESTING fast_remove_all(1)" << endl;
  list->fast_remove_all(1);
  list->print();


  // insert_sorted(sortedList)
  cout << "TESTING insert_sorted(sortedList)" << endl;
  cout << "original: ";
  listTest2->print();
  cout << endl << "adding 5: ";
  listTest2->insert_sorted(6);
  listTest2->print();
  listTest2->insert_sorted(-22);
  listTest2->print();
  listTest2->insert_sorted(66);

  listTest2->print();

  cout << endl;

  //will test concat() function
  cout << "TESTING concat(list) " << endl;
  cout << "list2: ";
  list2->print();
  cout << endl << "list3: ";
  list3->print();
  cout << endl << "list2.concat(list3): ";
  list2->concat(*list3);
  cout << endl << "after concat list2 ";
  list2->print();
   cout << endl << "after concat list3 ";
  list3->print();

  //testing compare_with
List<int> *list5 = new List<int>();

  list5->push_front(2);
  list5->push_front(2);
  list5->push_front(2);
List<int> *list6 = new List<int>();
  list6->push_front(1);
  list6->push_front(1);
  list6->push_front(1);
List<int> *list7 = new List<int>();
  list7->push_front(2);
  list7->push_front(2);
  list7->push_front(2);


  cout << "TESTING compare_with(list) " << endl;
  int out = list5->compare_with(*list6);
  if (out == 0)
  {
      cout << "IDENTICAL LISTS" << endl;
  }else if ( out == 1){
      cout << "other list is lexically before calling list" << endl;
  }else if ( out == -1){
      cout << "calling list is lexically before other list" << endl;
  }


  //clonin a list
  cout << "TESTING clone() function" << endl;
  

  // list2->front = NULL;
  

  delete list;
  delete list2;
  delete list3;

  /***  UNCOMMENT THIS CODE ONCE YOU HAVE WRITTEN YOUR
   *     slow_list FUNCTION

  list = slow_list(n);

  cout << "starting slow_remove_all (n=" << n << ")" << endl;
  ndel = list->slow_remove_all(0);
  cout << "slow_remove_all done!" << endl;
  cout << "    num-deleted:    " << ndel << endl;
  cout << "    list-len after: " << list->length()   << endl;

  delete list;

  ***/

  return 0;
}
