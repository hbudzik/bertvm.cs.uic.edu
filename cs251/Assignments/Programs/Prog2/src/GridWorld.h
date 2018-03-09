
#include "GWInterface.h"
#include <vector>
#include <iostream>

//                 (debugg == true) ? std::cout << " \n" 
//                                    : std::cout;

using std::vector;
bool debugg = false;

class GridWorld : public GWInterface {

  public:
    GridWorld(unsigned nrows, unsigned ncols)   {
//debugg start
(debugg == true)  ? std::cout << "calling.. GridWord::GridWorld(" << nrows << ", " << ncols << ")\n" 
                      : std::cout << " ";
//debugg end
      // your constructor code here!
      totR = nrows; //sets totR
      totC = ncols; //sets totC

      // creating a 2D array using nrows and ncols parameters
//debugg start
(debugg == true) ? std::cout << "\t- initializing arr[" << nrows << "][" << ncols << "]\n" 
                 : std::cout << " ";
//debugg end
       //initializing grid 
      grid = new int* [nrows];
      for (int row = 0; row < nrows; row++){
        grid[row] = new int[ncols];
      }
   
//debugg start
    //populates with random shit and prits it out
    if (debugg == true){
      int n = 0;
       for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
          grid[i][j] = n;
          n++; 
        }
      }

    for (int i = 0; i < nrows; i++){
    std::cout << "\t";
        for (int j = 0; j < ncols; j++){
          std::cout << "\t" << grid[i][j];
        }
    std::cout << std::endl;
    }
    std::cout << "exiting.. GridWord::GridWorld constructor" << std::endl;
    }
//end debugg
    }
    ~GridWorld(){
    (debugg == true)  ? std::cout << "calling.. ~GridWord::GridWorld (not implemented yet)\n" 
                      : std::cout << " "; 
      // your destructor code here.
      (debugg == true)  ? std::cout << "\tdeleting grid[pointers]\n" 
                        : std::cout << " ";
      for (int row = 0; row < totR; row++){
        (debugg == true)  ? std::cout << "\t\tdeleting grid[" << row << "]\n" : std::cout << " ";
          delete grid[row];
        }
      
      (debugg == true)  ? std::cout << "\tdeleting grid\n" : std::cout;
      delete grid;
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
      return totR;
    }
    int num_cols()const {
      return totC;
    }

  //helper functions:
  void printGrid(){

    return;
  }

  private:
  // private stuff goes here!

  /*
   * Creates a node called DYSTRICT that will contain a list of population in that district
   */
  struct DYSTRICT{
      int r, c;

      DYSTRICT * next = nullptr;
      DYSTRICT * prev = nullptr;
  };

    //   typedefs

    //   data members
    int ** grid;

    int totR; //number of rows in the world                      
    int totC; //number of columns in the world

    //   private helper functions

    //   etc.

};
