#include <iostream>
#include "bst.h"

int main(int argc, char** argv)
{
  int target;
  bst<int>* list1 = new bst<int>;

            //takes users input untill input -999 reached
            std::cout << "enter value: ";
            std::cin >> target;
            while ( target != -999 )
            {
              list1->bst_insert(target);
              std::cin >> target;
            }

  //inserts target into binary search tree
  target = 5;


  //checks if list contains target
  int x = list1->contains(target) ;
  (x == 1) ? std::cout << "found\n" : std::cout << "not found\n";

  list1->bst_print();

  //deallocates memory
  delete list1;
  return 0;
}
