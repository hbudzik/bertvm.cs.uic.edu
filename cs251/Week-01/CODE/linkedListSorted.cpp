#include <iostream>
#include <ctime>

using namespace std;


struct NODE {
    int val;
    int size = 5;
    NODE *next;
};


void populateList(NODE *lst);

////oid printList(NODE *lst);

//void listSorted(NODE *lst);



int main()
{
    struct NODE *lst = new struct NODE;


    //populate the linked list
    populateList(lst);

    //print list
    //printList(lst);

    //is it sorted ?
   // listSorted(lst);

    //delete list
    delete lst;
    return 0;
}

void populateList(NODE *lst)
{
    srand(time(0));
    //populating list 
    while (lst != NULL)
    {
        int n = 0;
        n = n + 1;
        
        lst->val = rand() % 50 + 1; // +1 sor its between 1-50 not 0 - 49
        cout << endl << "value: " << lst->val << endl;

        lst = lst->next;
             
        //adds next node 
        if (n < 5)
        {
            
            lst = new struct NODE;    //creates and allocates memory for new NODE
         
        }
    }
    return;
}

/*
void printList(NODE *lst)
{

    
}

void listSorted(NODE *lst)
{

    
}*/