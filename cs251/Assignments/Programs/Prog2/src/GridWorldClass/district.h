#include <vector>
#include <iostream>
using namespace std;

class district
{
  private:
   
    //Struct for members in the district
    struct NODE {
      int id;
      NODE* next = nullptr;
      NODE* prev = nullptr;
    }; 

  public:

    //initializes a class
    district() 
    {
      //(debugg == true)  ? std::cout << "calling.. GridWord::GridWorld(" << nrows << ", " << ncols << ")\n" : std::cout << " ";
      init();
    }

    ~district()
    {

    }

  private:
    
    //pointers for the front and back NODE of the DLL 
    NODE* front;
    NODE* back;
    int population = 0;   //current population in this district
   
   //helper functions
    void init()
    {
      front = nullptr;
      back = nullptr;
    }
};
