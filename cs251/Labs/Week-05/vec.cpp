#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

/**
 * short vector demo program
 */

int main(int argc, char *argv[]){
  vector<string> *vec;

  vec = new vector<string>();

  vec->push_back("abc");
  vec->push_back("xyz");
  vec->push_back("pqr");

  for(int i=0; i<vec->size(); i++) {
    // we can use square brackets like arrays
    //   (note that vec is a vector pointer
    //    so we apply the [] operator to *vec)
    cout << (*vec)[i] << endl;
  }

  cout << endl;

  // alternatively C++11 lets us do a "foreach" loop
  for(string s : *vec) {
    cout <<   s <<  endl;
  }

  // let's change one of the entries

  cout << endl;
  (*vec)[1] = "HELLO";
  cout << "after changing (*vec)[1]" << endl;

  cout << endl;
  for(string s : *vec) {
    cout <<   s <<  endl;
  }

  // the concatenation operator on strings:
  //
  //   string1 + string2
  
  vec->push_back( (*vec)[0] + (*vec)[1]);
  cout << endl;
  for(string s : *vec) {
    cout <<   s <<  endl;
  }

  delete vec;

  return 0;
}
