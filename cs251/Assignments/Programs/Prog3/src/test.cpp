#include <iostream>
#include "bst.h"


int main(){
    int x;
    int nleaves;
    int h;

    bst<int> *t = new bst<int>();

    while( (std::cin >> x)) 
        t->insert(x);

    if(t->size() <= 20) {
       t->inorder();
	   t->preorder();
	   t->postorder();
    }

    h = t->height();
    std::cout << "\n#### Reported height of tree:   " << h << "\n";

    nleaves = t->num_leaves();
    std::cout << "\n#### Reported number of leaves:   " << nleaves  << "\n";

    //checking vector size 
    std::cout << "\nnew vector size: " << t->to_vector()->size(); 
    
    std::cout <<"checking bookkeeping.. \n";
    std::cout <<"leftCount: " << t->getLeftCount();
    std::cout <<"\nrightCount: " << t->getRightCount();
    
    std::cout << "\ntmax: " << t->getMax();
    std::cout << "\ntmin: " << t->getMin();
    std::cout << "\ntSize: " << t->gettSize();

    std::cout << "\n";
    int nodevalue = 22;
    std::cout << "\ncontains: " << nodevalue; std::cout << ": " << t->contains(nodevalue);
    std::cout <<"\ngeq " << nodevalue; std::cout << ": " << t->num_geq(nodevalue);
    std::cout <<"\nleq " << nodevalue; std::cout << ": " << t->num_leq(nodevalue);
    std::cout << "\n";

    delete t;
    
    return 0;
}
