#include <iostream>


/*
 *	description:
 *  	this is a simple tree class with these elements
 *
 *  structs:
 *		bst_node
 *			val			//data int, or char
 *			left		//left side of the tree
 *  		ritgh		//right side of the tree
 *
 *	functions:
 *  	int contains(T target)	//returns 1 if tree contains target, 0 if not
 * 		int bst_insert(T value)			//inserts a new node with new value into the tree
 *		void print()								//printsout all the nodes smallest to largest
 *
 */
template<typename T>
class bst			//t for tree
{
    private:
    	struct bst_node{
				T val;
				bst_node* left;
				bst_node* right;
	    };

			bst_node* root;
	    void init() {
				std::cout << "init.. root" << std::endl;
	    	root = nullptr;	//init
	    }

	  public:
		  bst(){
	        std::cout << "calling t()\n";
					init();
	  	}

    //setters

		//getters

		//other
		void bst_print(){
			print(root);
		}

		int contains(T target) {
			//returns 1 if tree contains value, ret 0 if tree does not
				bst_node* p= root;	//creates new node and equals it to root node
	    	while(p != nullptr) {
	    		if(p->val == target)	{
		    		return 1;	//value found in the tree
	    			if(target < p->val)	//checks if target is less or greater then current node value
		    		p = p->left;
	    		}else{
		    		p = p->right;
					}
				}//end while loop
		  return 0;		//value not found in the tree
	 	}//end contains()

		void bst_insert(T value)	{
			insert(root, value);
    }//end insert()

  private:
		//helper functions
		//inserts new node
		void insert(bst_node* p, T value)	{
			bst_node *leaf;

				if ( p == nullptr) {
					leaf = new bst_node;
					leaf->left = nullptr;
					leaf->right = nullptr;
					leaf->val = value;
					this->root = leaf;
					return;
	      }
			 //if value already exists;
			 if ( p->val == value) {
				 		std::cout << "already exists\n";
				 		return;
			   }
			 //left side
			 if ( value < p->val ) {
				 std::cout << "left\n";
				 insert(p->left, value);
				 return;
			 }else{
				 std::cout << "right\n";
				 insert(p->right, value);
				 return;
			 }
		 }//endof insert()

		//prints out the whole list
		void print(bst_node* p)	{
			//base case
			if ( p == nullptr) {
				return;
			}
			//print left
			while( p != nullptr )  {
				print (p->left);
				std::cout << p->val << " ";
				return;
			}
			//print right
			while ( p != nullptr )  {
				std::cout << p->val << " ";
				print (p->right);
				return;
			}
	}//end print()
};
