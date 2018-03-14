#ifndef _STACK_H
#define _STACK_H

// #include <algorithm>
#include <iostream>
#include <time.h>

#define INIT_CAP  16
#define EXTRA_CAP 16

// using namespace std;

template <typename T>
class Stack {


  public:
    // constructors
    Stack (bool dbl_policy = true ) { 
      this->dbl_policy = dbl_policy;
      cap = INIT_CAP;
      data = new T[INIT_CAP];
      top = -1;
    }

    ~Stack( ) {
      delete data;
    }


    void clear(){
      top = -1;
    }



    int size( ) const {
      return top + 1;
    }


    // Return true if the list is empty, false otherwise.
    bool is_empty( ) const {
      return top == -1;
    }

  private:
    void resize() {
      T *new_data;
      int new_cap;
      int i;

      if(dbl_policy)
        new_cap = 2*cap;
      else
        new_cap = cap + EXTRA_CAP;

      new_data = new T[new_cap];
      for(i=0; i<= top; i++) 
        new_data[i] = data[i];

      delete data;
      data = new_data;
      cap = new_cap;
    }

  public: 


    void push(const T & val) {
      if(top == cap-1)
        resize();
      top++;
      data[top] = val;
    }

    bool pop(T &val) {
      if(top == -1)
        return false;
      val = data[top];
      top--;
      return true;
    }


  private:

    T *data;
    int cap;  // dimension of current data[] buffer
    int top;
    bool dbl_policy; // true if we double capacity of buffer on resize
                     // if false:  we expand capacity by an additive constant

};

#endif
