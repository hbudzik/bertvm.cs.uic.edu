
#ifndef __UTIL_H
#define __UTIL_H

#define __N 1000
#define __NTRIALS 10000

/** GLOBAL LISTS AND ARRAYS FOR CONVENIENT ACCESS **/


List<int> * lsts[20] = {nullptr};

/** END GLOBALS **/

void cleanup(){
  int n = sizeof(lsts)/sizeof(List<int> *);
  int i;


  for(i=0; i<n; i++) {
    if(lsts[i] != nullptr) 
      delete lsts[i];
    lsts[i]=nullptr;
  }
}

List<int> * one_to_n_lst(int n) {
List<int> *lst;

  lst = new List<int>();
  while(n) {
    lst->push_front(n);
    n--;
  }
  return lst;
}
  
// destructive
bool eq2array(List<int> *lst, int a[], int n) {
  int ret = true;
  int i, x;

  if(lst->length() != n){
    if(Verbose) {
       ERRMSG("eq2array: TYPE-1 err - list and array not of same length");
    } 
    return false;
  }

  for(i=0; i<n; i++) {
    if(!lst->pop_front(x) ) {
      if(Verbose) {
         ERRMSG("eq2array: TYPE-2 err - unexpected pop_front failure");
      }
      return false;
    }
    if(x != a[i]){
      ret = false;
      if(Verbose) {
        ERRMSG("eq2array: TYPE-3 err - mismatch [i, a[i], x] = ", 
            i, a[i], x);

      }
    }
  }
  return ret;

}


List<int> * arr2list(int a[], int n) {
  List<int> *lst = new List<int>();

  int i;

  for(i=0; i<n; i++)
    lst->push_back(a[i]);
  return lst;
}

bool lst_eq_arr(List<int> *lst, int a[], int n) {
int n2=0;
int i=0;
int x;

  while(i<n && !lst->is_empty()) {

    if(!lst->pop_front(x)){
      return false;
    }
    if(x != a[i])
      return false;
    i++;
  }
  if(i<n || !lst->is_empty())
    return false;
  return true;

}

// determines if lists a and b have same elements
//   (in the same order) without relying on the 
//   equal_to function.
//
//   This function is destructive -- it empties the
//   lists in the process.
bool lsts_equal_destructive(List<int> *a, List<int> *b) {
  int n;
  bool ret=true;
  int x, y;

  while(!a->is_empty() && !b->is_empty()) {
    if(!a->pop_front(x)|| !b->pop_front(y)){
      ret = false;
      if(Verbose) 
        ERRMSG("lsts_equal_destructive: TYPE-1 err; one or both pop_front calls failed");

    }
    if(x != y) {
      ret = false;
      if(Verbose) 
        ERRMSG("lsts_equal_destructive: TYPE-2 err; popped values do not match");
    }
  }
  if(!b->is_empty() || !a->is_empty()){
    ret = false;
    if(Verbose) 
      ERRMSG("lsts_equal_destructive: TYPE-3 err; one list non-empty");
  }
  return ret;
} 


#endif
