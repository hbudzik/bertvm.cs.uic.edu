
#include "GWInterface.h"
#include <vector>
#include <iostream>

using namespace std;

using std::vector;
using std::cout;
using std::endl;



class person
{
  private:

    int r, c;
    bool alive;

  public:
    //initializes a class
    person()
    {
      
    }

    ~person()
    {
      
    }

    //setter functions
    void createPerson(int row, int col)
    {
      r = row;
      c = col;
      alive = true;
    }

    void setDead(){
      alive = false;
      return;
    }

    void setRow(int row)
    {
      r = row;
    }

    void setCol(int col)
    {
      c = col;
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

    void setAlive() const
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
      init();
    }

    ~district()
    {
      delete distMembers; //removes vector at the end
      clean();
    }

    //setters
    void rmVector(int id)
    {
       // erase the 6th element
       for (unsigned i=0; i<distMembers->size(); i++)
       {
        if ( distMembers->at(i) == id){
          distMembers->erase (distMembers->begin()+ i-1);
        }
       }
    }


    //getters

  
    void rmPop()
    {
      distPop--;
    }

    int getPop() const
    {
      return distPop;
    }

    vector<int> *memberList()                                             //vector<int> *memberList
    {
      return distMembers;
    }

    int vectorSize() const                                             //vector<int> *memberList
    {
      return distMembers->size();
    }

    void addVector(int x) const
    {
      distMembers->push_back(x);
      return;
    }

    void rmNode(int id)
    {
      popNode(id);
    }

    void createMember(int ID)
    {
      if (this->front == nullptr)  { //empty list
        pushFront(ID);
        //updates distMembers and distPopwith new id
        addVector(ID);
        cout << "vectormember FIRST size: " << distMembers->size() << endl;
        distPop++;
      }else{ //at least one node adds to the back
        addVector(ID);
        cout << "vectormember AFTER size: " << distMembers->size() << endl;
        //updates distMembers with new id
        distPop++;
      }
    }

    void addMember()
    {

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

    void popNode(int id)
    {
      //first node
      NODE* tmp;
      NODE* p;
        if (this->front->id == id)
        {
          tmp = this->front;
          this->front = this->front->next;
          delete tmp;
          return;
        }

        //last node
        if (this->back->id == id)
        {
          tmp = this->back;
          this->back = this->back->prev;
          delete tmp;
          return;
        }
        
        //in between 
        p = this->front->next;
        while(p != nullptr)
        {
          if (p->id == id)  //found the node
            { 
              p->prev->next = p->next;
              p->next->prev = p->prev;
              delete p;              
            }
          p = p->next;       
        }
    }
};


class GridWorld : public GWInterface
{
  private:
    district** world;
    district deadpool;
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
      totR = nrows; //sets totR
      totC = ncols; //sets totC
      // creating a 2D array using nrows and ncols parameters
      //initializing grid
      world = new district* [nrows];
      for (int row = 0; row < nrows; row++)
      {
        world[row] = new district[ncols];
      }
    }

    ~GridWorld()
    {
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
      //adding a person to the world
        personAdd(row, col, IDbookeeping);
        //updates total population an ID in the world
        totPopulation++;
        IDbookeeping++;
      return true;
    }

    bool death(int personID){                                                   //(99999999999999999)
      totPopulation--;

      int origRow = people[personID].getRow();
      int origCol = people[personID].getCol();  
      world[origRow][origCol].rmPop();                     
      //changes status to dead
      people[personID].setDead();
      //removing member
      world[origRow][origCol].rmVector(personID);
       //moving to deadpool
             
      world[origRow][origCol].rmNode(personID);

      return true;
    }

    bool whereis(int id, int &row, int &col)const{
      row = people[id].getRow();
      col = people[id].getCol();
      return true;
    }

    bool move(int id, int targetRow, int targetCol){
      //setting person first
      int origRow = people[id].getRow();
      int origCol = people[id].getCol();

      people[id].setRow(targetRow);
      people[id].setCol(targetCol);

      //moving the node
      personMove(targetRow, targetCol, id);
      
      //deleting old node
      world[origRow][origCol].rmNode(id);
      //removing member
      world[origRow][origCol].rmVector(id);
     


      return true;
    }


    //returns the list of members living in that district(their IDs )
    std::vector<int> * members(int row, int col)const
    {
      vector<int> * tmp = world[row][col].memberList();
      vector<int> * ret = new vector<int>(); 
      for (int d : *tmp)
      {
        ret->push_back(d);
      }                                                                   
      return ret;
    }

    int population()const{
      vector<int> * ret = world[1][1].memberList();
      cout << "ret size: " << ret->size() << endl;     
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

    void personMove(int row, int col, int IDbookeeping)
    {
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
