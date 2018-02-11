#include <iostream>
#include <ctime>

using namespace std;

struct NODE
{
    int data;
    NODE *next = NULL;
};


void addToBack(NODE* & list, int val);

void printList(NODE* & pHead);

int main ()
{
    NODE * list = NULL;
   
    cout << "start adding numbes type -999 to stop " << endl;
    int x;
    while (true)
    {

        cout << ":> ";
        cin >> x;
        if (x == 0)
            break;

        addToBack(list, x);
    }
    
 
    //prints out the list
    printList(list);

    delete list;
    return 0;
}

void addToBack(NODE * & list, int val)
{
    //if list is empty
    if(list == NULL){
        list = new NODE;
        list->data = val;
        return;
    }
   
    //if list is not empty add to the last postion
    NODE * newNode = new NODE;
    NODE * pHead = list;

    newNode->data = val;


    while (true)
    {
        if (pHead->next == NULL)
        {
            pHead->next = newNode;
            break;
        }
        //moves along the list till last node
        pHead = pHead->next;
    }
return;
}

void printList(NODE * & list)
{
    NODE *pHead = list;
    //checking if list is empty
    if (pHead == NULL)
    {
        cout << "empty list" << endl;
        return;
    }
    
    //list not empty 
    while (pHead != NULL)
    {
        cout << "\tdata: " << pHead->data << endl;
        pHead = pHead->next;
    }
}