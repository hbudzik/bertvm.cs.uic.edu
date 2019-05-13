#include <iostream>

using namespace std;

template <typename T>
class heap
{
  private:
    //
    struct heap_node
    {
        T val;
        heap_node *left;
        heap_node *right;
    };

    heap_node *root; //declaring root

    //constructor
    void init()
    {
        root = nullptr; //init
    }

    //removes all the nodes from the tree
    void freeup(heap_node *r)
    {
        if (r == nullptr)
            return;

        freeup(r->left);
        freeup(r->right);
        delete r;
    }

    // **** PRINTING bst preorder, inorder, postorder ****
    void in_order(heap_node* r){
        //basecase
        if (r == nullptr) return;
        //if not null traverse 
        in_order(r->left);
        std::cout <<  r->val << " ";
        in_order(r->right);
    }

  public:
    //constructor
    heap()
    {
        init();
    }

    //destructor
    ~heap()
    {
        freeup(root);
    }

    /*  description:    prints out the node
    *
    */    
   void heap_print(){
        in_order(root);
    }

};