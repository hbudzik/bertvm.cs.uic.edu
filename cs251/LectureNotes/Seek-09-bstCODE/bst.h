#include <iostream>

template <typename T>
class bst
{
  private:
    //
    struct bst_node
    {
        T val;
        bst_node *left;
        bst_node *right;
    };

    bst_node *root; //declaring root

    //constructor
    void init()
    {
        root = nullptr; //init
    }


    //***helper function for bst_insert()
    bst_node* insert (bst_node* r, T val) {  
        bst_node* leaf;
        
        //if tree empty or located null leaf
        if (r == nullptr){

            //creating and initializing all vars in new nodes
            leaf = new bst_node;
            leaf->left = nullptr;
            leaf->right = nullptr;
            leaf->val = val;    //done intit new node
            //returns new leaf
            return leaf;
        }

        //if tree already contains the value 
        if (r->val == val){
            return r;   //returns current node r = r is assigned, overrides itsself 
        }

        if(val < r->val){
            r->left = insert(r->left, val);
        }else{
            r->right = insert(r->right, val);
        }
    }

    // **** PRINTING bst preorder, inorder, postorder ****
    void in_order(bst_node* r){
        //basecase
        if (r == nullptr) return;
        //if not null traverse 
        in_order(r->left);
        std::cout <<  r->val << " ";
        in_order(r->right);
    }

    //removes all the nodes from the tree
    void freeup(bst_node* r){
        if ( r == nullptr) return;

        freeup(r->left);
        freeup(r->right);
        delete r;        
    }

    //returns smalest value in the tree
    int h_min(bst_node* p){ 

        if (p->left == nullptr) {
            return p->val;
        }
        h_min(p->left);
    }

    int h_max(bst_node* p){ 

        if (p->right == nullptr) {
            return p->val;
        }
        h_max(p->right);
    }

  public:
    //constructor
    bst()
    {
        init();
    }

        //destructor
    ~bst() {
        freeup(root);
    }

    /*  description:    prints out the node
    *
    */    
   void bst_print(){
        in_order(root);
    }

    int bst_min(){
        h_min(root);
    }
    
    int bst_max(){
        h_max(root);
    }
   

    /*  description:    inserts node into the bst
    *
    */

    void bst_insert(T val) {
        root = insert(root, val);
    }

    /*  description:    inserts node into the bst
    *
    */

    void bst_remove(T val){
        //remove(root);
    }
    /*  description:    returns true if contains value, false otherwise
     *
     *  variables:      int x       - target value 
     *                  bst_node* t - pointer to tree root   
     */
    bool bst_contains(T x)
    {
        bst_node *p = root;    //creates temporary pointer for traversal 

        while (p != nullptr)
        {
            //checks for target value
            if (p->val == x)
            {
                return true; //contains target
            }

            //if values is smaller move to the left
            if (x < p->val)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        //after while loop is exhausted, meaning target is not found, return false
        return false;
    }


};