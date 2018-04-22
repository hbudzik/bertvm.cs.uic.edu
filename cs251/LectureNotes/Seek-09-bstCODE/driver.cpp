#include <iostream>
#include "bst.h"

using namespace std;
int main()
{
    bst<int>* list1 = new bst<int>;
    int userInput; 

    //populates the bst with some random numbers
    list1->bst_insert(5);
    for (int i=0; i < 10; i++){

        list1->bst_insert(2*i);
    }

    //menu
    cout << "MENU OPTIONS: \n";
    cout << "1) print \n";
    cout << "2) min/max \n";
    cout << "3) insert \n";
    cout << "4) remove \n";
    cout << "5) contains target\n";
    cout << "6) quit\n";

    int input;
    while(input!=-999)      //loops through switch untill quit is init.
    {
        cout << "> ";
        cin >> input;

        switch(input)
        {
            case 1 :    cout << "\t";
                        list1->bst_print();
                        break;
            case 2 : 
                        cout << "\tbst_min: " << list1->bst_min() << endl;
                        cout << "\tbst_max: " << list1->bst_max() << endl;
                        break;
            case 3 : 
                        cout << "\t: ";
                        cin >> userInput;
                        list1->bst_insert(userInput);
                        break;
            case 4 :
                        cout << "\t: ";
                        cin >> userInput;
                        list1->bst_remove(userInput);
                        break;
            case 5 :    
                        cout << "\t: ";
                        cin >> userInput;
                        if ( list1->bst_contains(userInput) == true){
                            cout << "\tTRUE";
                        }else{
                            cout << "\tFALSE";
                        }
                        break;
            case 6 : 
                        cout << "\tquitting";
                        input = -999; //breaks from while loop
                        break;
            default : 
                        cout << "\tWRONG INPUT\n";
                            cout << "\tMENU OPTIONS: \n";
                            cout << "\t1) print \n";
                            cout << "\t2) min/max \n";
                            cout << "\t3) insert \n";
                            cout << "\t4) remove \n";
                            cout << "\t5) contains target\n";
                            cout << "\t6) quit\n";
                        continue;
        }
    cout << "\n";
    }   
 
//freeing memory 
delete list1;
return 0;
}