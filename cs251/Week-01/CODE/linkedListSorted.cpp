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

bool listSort(NODE* & list);

//recursive functions
bool listSort_R(NODE* & list);

void printList_R(NODE * & list);

void printListReverse_R(NODE * & list);

int main ()
{
    NODE * list = NULL;
   
    cout << "start adding numbes type -999 to stop " << endl;
    int x;
    
    //takes input and populates the linked list
    while (true)
    {
        cout << ":> ";
        cin >> x;
        if (x == 0)
            break;
        //adds to the end of linked list
        addToBack(list, x);
    }
    
    //prints out the list
    printList(list);

    //checks if list is sorted ?
    if ( listSort(list) == true){
        cout << "SORTED!! " << endl;
    }else if (listSort(list) == false)
    {
            cout << "UNSORTED" << endl;
    }

    cout << "*** *** *** ***" << endl;
    cout << "RECURSIVE FUNCTIONS " << endl;

    //prints recursivly
    cout << "prints Recursivly: \t";
    printList_R(list);
    cout << endl;

    //prints in reverse recursivly 
    cout << "prints in reverse: \t";
    printListReverse_R(list);
    cout << endl << endl;
    cout << "recursive sorted? : ";

    //checks if list is sorted RECURSIVLY 
    if ( listSort_R(list) == true){
        cout << "SORTED!! " << endl;
    }else if (listSort_R(list) == false)
    {
            cout << "UNSORTED" << endl;
    }

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

/*
another possible way to check if its sorted
bool lst_is_sorted(NODE *lst) {

  while(lst != NULL && lst->next != NULL){
    if(lst->val > lst->next->val)
        return false;
    lst = lst->next;
  }
  return true;
}
*/

bool listSort(NODE* & list)
{
    NODE *pHead = list;

    if (pHead == NULL || pHead->next == NULL)
        {
            return true;
        }
        
    while (pHead->next != NULL)
    {
        if(pHead->data > pHead->next->data)
            return false;

        pHead = pHead->next;
    }
return true;
}

bool listSort_R(NODE* & list)
{
    NODE *pHeadd = list;

    //base case
    if ( pHeadd == NULL || pHeadd->next == NULL )
    {  
        return true;
    }
    
    if ( pHeadd->data > pHeadd->next->data )
    {
       
        return false;
    }else{
        //recurion 
        return listSort_R(pHeadd->next);
    }
}

void printList_R(NODE * & list)
{
    //base case
    if (list == NULL)
        return;

    //prints before calling next node recursivly 
    cout << " " << list->data;
    printList_R(list->next);
}

void printListReverse_R(NODE * & list)
{
    //base case
    if (list == NULL)
    {
        return;
    }
   
    printListReverse_R(list->next);
    //prints after calling recursive function 
    cout << " " << list->data;
}