
#include "GWInterface.h"
#include <vector>
#include <iostream>

using namespace std;

using std::vector;
using std::cout;
using std::endl;
bool debugg = false;


class person
{
  private:

    int r, c;
    bool alive;

  public:
    //initializes a class
    person()
    {
      (debugg == true)  ? cout << "\tcreating a person\n" : cout << " ";
    }

    ~person()
    {
      (debugg == true)  ? cout << "\tdestroing a person\n" : cout << " ";
    }

    //setter functions

    void createPerson(int row, int col)
    {
      r = row;
      c = col;
      alive = true;
    }
    //getter functions
};


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
      (debugg == true)  ? std::cout << "\t\tcreating a district\n" : cout << " ";
      init();
    }

    ~district()
    {
      (debugg == true)  ? std::cout << "\t\t\tdestroing a district (NOT IMPLEMENTED)\n" : cout << " ";
      clean();
    }

    void createMember(int ID)
    {
      if (this->front == nullptr)  { //empty list
        (debugg == true)  ? std::cout << "\t\t\tcreating first member in a district\n" : cout << " ";
        this->front = new NODE;
        this->front->id = ID;
        this->back = this->front;
      }else{ //at least one node adds to the back
        (debugg == true)  ? std::cout << "\t\t\tcreating another member in a district\n" : cout << " ";
        NODE* tmp;
        //fixing next and prev nodes first
        this->back->next = tmp;
        this->back->next->prev = this->back;
        //updating back pointer
        this->back = this->back->next;
      }
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

    void clean()
    {
      //to be implemented
    }
};


class GridWorld : public GWInterface
{
  private:
    district** world;
    //   data members
      int totR;             //number of rows in the world
      int totC;             //number of columns in the world
      int totPopulation = 0;           //number of people in the world
      int IDbookeeping = 0;      //keeps an eye on current ID numbers
      //vector of type person
      // index is the persons IDs
      int vectSize = 2;
      std::vector<person> people = vector<person>(vectSize);
      //   typedefs
      //   private helper functions
      //   etc.

  public:
    GridWorld(unsigned nrows, unsigned ncols)   {

      (debugg == true)  ? std::cout << "calling.. GridWord::GridWorld(" << nrows << ", " << ncols << ")\n"
      : std::cout << " ";

      totR = nrows; //sets totR
      totC = ncols; //sets totC

      // creating a 2D array using nrows and ncols parameters

      (debugg == true) ? std::cout << "\t- initializing arr[" << nrows << "][" << ncols << "]\n"
      : std::cout << " ";

      //initializing grid
      world = new district* [nrows];

      for (int row = 0; row < nrows; row++)
      {
        (debugg == true) ? std::cout << "\t- initialized \n" : std::cout << " ";
        world[row] = new district[ncols];

      }
    }

    ~GridWorld()
    {
      (debugg == true)  ? std::cout << "\ncalling.. ~GridWord::GridWorld\n" : std::cout << " ";
      (debugg == true)  ? std::cout << "\tdeleting grid[pointers]\n" : std::cout << " ";

      // your destructor code here.
      for (int row = 0; row < totR; row++){
      (debugg == true)  ? std::cout << "\t\tdeleting grid[" << row << "]\n" : std::cout << " ";
        delete world[row];
      }

      (debugg == true)  ? std::cout << "\tdeleting grid\n" : std::cout << " ";
      delete world;
      (debugg == true)  ? std::cout << "exiting.. ~GridWord::GridWorld\n" : std::cout << " ";
    }//end ~gridWorld

    bool birth(int row, int col, int &id){
      //checks grid size
      if ( gridTest(row, col) == false ) { return false; }
      id = IDbookeeping;
      (debugg == true)  ? std::cout << "size of vector<people>: " << people.size() << endl : cout << " ";
      //checks people vector and resizes if necessery
        pplVectReSize(IDbookeeping);
      //adding a person to the world
        personAdd(row, col, IDbookeeping);
      //updates total population an ID in the world
        totPopulation++;
        IDbookeeping++;
      return true;
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


    //returns the list of members living in that district(their IDs )
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
    bool gridTest(int row, int col)
    {
      if (row < totR && col < totC){
        return true;
      }else{
        return false;
      }
    }
    void personAdd(int row, int col, int IDbookeeping)
    {
      people[IDbookeeping].createPerson(row, col);          //adds to people ADT
      world[row][col].createMember(IDbookeeping);           //adds to district ADT
      return;
    }

    void pplVectReSize(int ID)
    {
      if (ID == people.size()){
        people.resize(vectSize * 2);
        vectSize = vectSize * 2;
      }
    }
};
