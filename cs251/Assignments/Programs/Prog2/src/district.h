#include <vector>
#include <iostream>

using namespace std;


class district
{
  private:


    typedef struct NODE{
    //vector to keep track of members ID and for quick access
    vector<int> memberList(2);  //setting size to 2 MEMBERS
    int districtPopulation;;  //population in the district
    struct Members* front = nullptr;
    struct Members* back = nullptr;
    }DISTRICT;

    //initializes the NODE struct
    void init()
    {
      NODE* front = nullptr;
      NODE* back = nullptr;
    }

  public:

    //constructor
    district()
    {
      //initializes
      init();

    }

    //destructor
    ~district()
    {

    }

}
