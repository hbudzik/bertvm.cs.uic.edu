#include <vector>
#include <iostream>
#include <vector>
using namespace std;
class person
{
  private:
   
    //Struct for members in the district
    struct NODE {
        int r, c;
        int id;
        bool alive;
    }; 

  public:

    //initializes a class
    person() 
    {
      init();
    }

    ~person()
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
