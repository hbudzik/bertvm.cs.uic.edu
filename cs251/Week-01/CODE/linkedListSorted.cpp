#include <iostream>
#include <ctime>

using namespace std;


struct NODE {
    int val;
    int inUse = 0;
    struct NODE *next = nullptr;
};


void populateList(struct NODE *lst, int val);

void printList(struct NODE *lst);

//void listSorted(NODE *lst);



int main()
{
    struct NODE *front = new struct NODE;
    struct NODE *lst = front;

    //asks and adds new nodes with random numbers

    srand(time(0));
    int nodeNumber;
    int randomNumber;
    cout << "how many NODES in a linked list: ";
    cin >> nodeNumber;
    cout << endl << "you entered: " << nodeNumber << endl;


    for (int i = 0; i < nodeNumber; i++) {
        randomNumber = rand() % 50 + 1;

       lst

       cout << "val: " << lst->val;
       cout << "   InUse: " << lst->inUse << endl;
    }
  
    
    
    //populate the linked list
    //populateList(lst, randomNumbert);

    //print list
    printList(front);

    //is it sorted ?
   // listSorted(lst);

    //delete list
    delete lst;
    delete front;
    return 0;
}

void populateList(struct NODE *lst, int val)
{
    //checks if list is empty

    struct NODE *pHead = lst;

    if (pHead != nullptr) {
        pHead->val = val;
        pHead->inUse++;
        pHead = pHead->next;
    }else{
    struct NODE *tmp = new struct NODE;
    tmp->val = val;
    tmp->inUse = pHead->inUse + 1;
    pHead->next = tmp;
    delete tmp;
    }
    return;
}


void printList(struct NODE *lst)
{
    while ( lst != nullptr)
    {
         cout << "\t" << lst->val << endl;
         lst = lst->next;
    }

    cout << "nullptr reached";
    return;
}

/*
void listSorted(NODE *lst)
{

    
}*/