
#include "GWInterface.h"
#include <vector>
#include <iostream>

using std::vector;


class GridWorld : public GWInterface {

  public:
    GridWorld(unsigned nrows, unsigned ncols)   {

      // your constructor code here!
    }
    ~GridWorld(){
      // your destructor code here.
    }

    bool birth(int row, int col, int &id){
      return false;
    }

    bool death(int personID){

      return false;
    }

    bool whereis(int id, int &row, int &col)const{
      return false;
    }

    bool move(int id, int targetRow, int targetCol){
      return false;
    }

    std::vector<int> * members(int row, int col)const{

      return nullptr;
    }

    int population()const{
      return 0;
    }
    
    int population(int row, int col)const{
      return 0;
    }

    int num_rows()const {
      return 0;
    }
    int num_cols()const {
      return 0;
    }


  private:

    // private stuff goes here!
    //   typedefs
    //   data members
    //   private helper functions
    //   etc.

};
