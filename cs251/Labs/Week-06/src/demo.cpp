#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>



using namespace std;


int main(int argc, char *argv[]){
  List<string> *words = new List<string>;
  string s;

  while(cin >> s ) {
    words->push_back(s);
  }
  cout << "BEFORE SORTING:\n";
  words->print();

  words->qsort();
  cout << "AFTER SORTING:\n";
  words->print();

  delete words;

  return 0;
}
