
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
      (debugg == true)  ? cout << "\tinit... person()\n" : cout << " ";
    }

    ~person()
    {
      (debugg == true)  ? cout << "\tinit... ~person()\n" : cout << " ";
    }

    //setter functions
    void createPerson(int row, int col)
    {
      r = row;
      c = col;
      alive = true;
    }
    //getter functions
    int getRow() const
    {
      return r;
    }

    int getCol() const
    {
      return c;
    }

    void getAlive() const
    {
      ( alive == true) ? cout << "Alive" << endl : cout << "Dead" << endl;
      return;
    }
};


class district
{
  private:
    //counts members in current district
    int distPop = 0;
    //Struct for members in the district
    struct NODE {
      int id;
      NODE* next = nullptr;
      NODE* prev = nullptr;
    };
    //vector storing all the members in this district by their IDs

    vector<int> *distMembers = new vector<int>();

  public:
    //initializes a class
    district()
    {
      (debugg == true)  ? std::cout << "\t\tinit... district()\n" : cout << " ";
      init();
    }

    ~district()
    {
      (debugg == true) ? std::cout << "\t\t\tinit... ~district\n" : cout << " ";
      delete distMembers; //removes vector at the end
      clean();
    }

    //setters

    //getters

    int getPop() const
    {
      return distPop;
    }

    vector<int> *memberList()const
    {
      return distMembers;
    }

    void addVector(int x) const
    {
      distMembers->push_back(x);
      return;
    }

    void createMember(int ID)
    {
      if (this->front == nullptr)  { //empty list
        (debugg == true)  ? std::cout << "\t\t\tcreating first member in a district\n" : cout << " ";
        pushFront(ID);
        //updates distMembers and distPopwith new id
        addVector(ID);
        cout << "vectormember size: " << distMembers->size() << endl;
        distPop++;
      }else{ //at least one node adds to the back
        (debugg == true)  ? std::cout << "\t\t\tcreating another member in a district\n" : cout << " ";
        addVector(ID);
        cout << "vectormember size: " << distMembers->size() << endl;
        //updates distMembers with new id
        distPop++;
      }
    }


  private:
    NODE* front;
    NODE* back;


    void init()
    {
      front = nullptr;
      back = nullptr;
    }

    void clean(){
      //traverse through the list and free memory
      while(this->front != nullptr){
        this->back = this->front;
        this->front = this->front->next;

        (debugg == true)  ? std::cout << "\t\t\t\tremoving member NODE\n" : cout << " ";
        delete this->back;    //member node remove
      }
    }

    void pushFront(int ID)
    {
      this->front = new NODE;
      this->front->id = ID;
      this->back = this->front;
      return;
    }

    void pushBack(int ID)
    {
        NODE* tmp = new NODE;
        tmp->id = ID;
        tmp->prev = this->back;
        //fixing next and prev nodes first
        this->back->next = tmp;
        //updating back pointer
        this->back = this->back->next;
        return;
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
      // vector<person> index is the persons IDs
      int vectSize = 2;
      std::vector<person> people = vector<person>(vectSize);
      //   typedefs
      //   private helper functions
      //   etc.

  public:
    GridWorld(unsigned nrows, unsigned ncols)   {

      (debugg == true)  ? std::cout << "init... grid world(" << nrows << ", " << ncols << ")\n" : std::cout << " ";
      totR = nrows; //sets totR
      totC = ncols; //sets totC
      // creating a 2D array using nrows and ncols parameters
      (debugg == true) ? std::cout << "\t- init... 2d array.\n" : std::cout << " ";
      //initializing grid
      world = new district* [nrows];
      for (int row = 0; row < nrows; row++)
      {
        world[row] = new district[ncols];
      }
    }

    ~GridWorld()
    {
      (debugg == true)  ? std::cout << "\ninit... ~GridWord\n" : std::cout << " ";
      (debugg == true)  ? std::cout << "\tdeleting districts\n" : std::cout << " ";

      // your destructor code here.
      for (int row = 0; row < totR; row++){
        delete [] world[row];
      }
      delete world;
    }//end ~gridWorld

    bool birth(int row, int col, int &id){
      //checks grid size
      if ( gridTest(row, col) == false ) { return false; }
      id = IDbookeeping;
      //checks people vector and resizes if necessery
        pplVectReSize(IDbookeeping);
        (debugg == true)  ? std::cout << "size of vector<people>: " << people.size() << endl : cout << " ";
      //adding a person to the world
        personAdd(row, col, IDbookeeping);
        (debugg == true) ? std::cout << " \t\t\t\tID <" << IDbookeeping << "> row: " << people[IDbookeeping].getRow() << endl : std::cout << " ";
        (debugg == true) ? std::cout << " \t\t\t\tID <" << IDbookeeping << "> col: " << people[IDbookeeping].getCol() << endl : std::cout << " ";
        (debugg == true) ? std::cout << " \t\t\t\tID <" << IDbookeeping << "> is: " : std::cout << " ";
        if (debugg == true){ people[IDbookeeping].getAlive(); }
        //updates total population an ID in the world
        totPopulation++;
        IDbookeeping++;
      return true;
    }

    bool death(int personID){

      return false;
    }

    bool whereis(int id, int &row, int &col)const{
      row = people[id].getRow();
      col = people[id].getCol();
      return true;
    }

    bool move(int id, int targetRow, int targetCol){
      return false;
    }


    //returns the list of members living in that district(their IDs )
    std::vector<int> * members(int row, int col)const
    {
      vector<int> * ret = world[row][col].memberList();

      return ret;
    }

    int population()const{
      return totPopulation;
    }

    int population(int row, int col)const{

      return world[row][col].getPop();
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
