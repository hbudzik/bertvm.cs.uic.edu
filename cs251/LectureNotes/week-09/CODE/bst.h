#include <iostream
	    std::cout << "call t()\n";

template<typename T>
class t			//t for tree
{
    private:
    struct bst_node{
	T val;
	bst_node* left;
	bst_node* right; 
    };
    void init(){
	std::cout << "init.. root" << std::endl;
    	bst_node* root;	//init 
    }   

    }
    public: 
	t(){
	    std::cout << "call t()\n";
	    init();
	}
    //setters

    //getters
	int contains(T target) {
		//returns 1 if tree contains value, ret 0 if tree does not
	    bst_node* p=this->root;	//creates new node and equals it to root node
	    while(p != nullptr) {
	    	if(p->val == target)
		    return 1;	//value found in the tree
	    	if(target < p->val)	//checks if target is less or greater then current node value
		    p = p->left;
	    	else
		    p = p->right;
	    }//end while loop
	}//end contains()


};
