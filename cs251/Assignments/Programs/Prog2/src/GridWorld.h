
#include "GWInterface.h"
#include <vector>
#include <iostream>

//                 (debugg == true) ? std::cout << " \n"
//                                    : std::cout;

using std::vector;
bool debugg = false;

class GridWorld : public GWInterface
{
  private:
  // private stuff goes here!
  typedef struct Members{
    int id;
    Members* next = nullptr;
    Members* prev = nullptr;
    }MEMBERS;

   // struct for double-linked list nodes
    typedef struct District_NODE{
    //vector to keep track of members ID and for quick access
    vector<int> memberList(2);  //setting size to 2 MEMBERS
    int districtPopulation;;  //population in the district
    struct Members* front = nullptr;
    struct Members* back = nullptr;
    }DISTRICT;


  typedef struct Person{
    int r, c;     //where they live
    bool alive;
  }PERSON;



   //   data members
    DISTRICT** pgrid;     //creates pointer to the grid
    int totR;             //number of rows in the world
    int totC;             //number of columns in the world
    int totPopulation;           //number of people in the world
    int ID;           //ID of member
    //   typedefs
    //   private helper functions
    //   etc.



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

      //creating District
       //initializing grid
      pgrid = new DISTRICT* [nrows];

      for (int row = 0; row < nrows; row++){
        pgrid[row] = new DISTRICT[ncols];
        std::cout << "\t\tinitialized\n";
      }
    //debugg start
    //populates with random shit and prits it out
    /*
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
    std::cout << "exiting.. GridWord::GridWorld constructor\n" << std::endl;
    }
    //end debugg
    */
    }

    ~GridWorld() {
(debugg == true)  ? std::cout << "\ncalling.. ~GridWord::GridWorld\n"
                  : std::cout << " ";
      // your destructor code here.
(debugg == true)  ? std::cout << "\tdeleting grid[pointers]\n"
                  : std::cout << " ";

      for (int row = 0; row < totR; row++){
(debugg == true)  ? std::cout << "\t\tdeleting grid[" << row << "]\n" : std::cout << " ";
          
          delete pgrid[row];
        }

(debugg == true)  ? std::cout << "\tdeleting grid\n" : std::cout << " ";
      delete pgrid;

(debugg == true)  ? std::cout << "exiting.. ~GridWord::GridWorld\n" : std::cout << " ";
    }//end ~gridWorld

    bool birth(int row, int col, int &id){
      (debugg == true) ? std::cout << "calling.. GridWord::birth()\n" : std::cout << " ";
     // PERSON * id = new PERSON;

     //if its the first node added
     if ( pgrid[row][col].front == nullptr ) {
       totPopulation = 1; //starts counting total population
       //updates front and back pointers of DISTRICT struct
       //since there is only one NODE both front and back point to the same NODE
       (debugg == true) ? std::cout << "\tcreating FIRST NODE... \n" : std::cout << " ";
        pgrid[row][col].districtPopulation = 1;   //begins counting population in current district
        pgrid[row][col].front = new MEMBERS;
        pgrid[row][col].back = pgrid[row][col].front;
       //updates next and prev pointers of MEMBERS struct
       (debugg == true) ? std::cout << "\tupdating front and back pointers in DISTRICT \n" : std::cout << " ";
        pgrid[row][col].front->next = nullptr;
        pgrid[row][col].front->prev = nullptr;

        //updating new member ID
        (debugg == true) ? std::cout << "\tupdating new member ID now( NOT IMPLEMENTED PROPERLY) \n" : std::cout << " ";
        pgrid[row][col].front->id = ID;
        id = ID;
        ID++;     //updates list
     }
     else {
       (debugg == true) ? std::cout << "\tadding ANOTHER NODE\n" : std::cout << " ";
        //create new node
        MEMBERS* tmp = new MEMBERS;
        (debugg == true) ? std::cout << "\tupdating next and prev in MEMBERS struct, and back pointers in DISTRICT\n" : std::cout << " ";
        tmp->next = nullptr;  //setting next pointer to null since its the last node
        tmp->prev = pgrid[row][col].back; //poiting to previous node
                //assigning ID to new members
        totPopulation++;  //updating total population
        //updating the back pointer
        pgrid[row][col].back->next = nullptr;

        //updating new member ID
        (debugg == true) ? std::cout << "\tupdating new member ID now( NOT IMPLEMENTED PROPERLY) \n" : std::cout << " ";
        pgrid[row][col].back->id = ID;
        id = ID;
        ID++;     //updates list





     }

      return true;
    }//end birth()

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
      return totPopulation;
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


};
