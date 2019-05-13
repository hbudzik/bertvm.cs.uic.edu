#include <iostream>
//#include "heap.h"           //binary heap does not use nodes, only array

using namespace std;
void perc_up(int arr[], int i)
{
    int x = arr[i];
    int p;  //indices for a parent node
    p = i/2;    //calculates 'i''s parent node

    while(p>0 && x < arr[p]){         //if p>0, parent is in the tree. x < h[p], the value of x, child, is smaller than value of h[p], parent, than switch
        arr[i] = arr[p];            //arr[i] is stored in x; and array[i] is overwriten by array[p], parent goes down becomes a child, and child percs up 
        i = p; p = i/2;             //now i takes place of parent, percs up, and p is calculated to become i's parent and process is repeted if while allows
    }
    arr[i] = x;
    return;
}

void td_build_heap(int arr[], int n)
{
    for (int i = 1; i<=n; i++)
    {
        perc_up(arr, i);
        
    }   
    return;
}

int min_child_idx(int arr[], int root, int n)
{
    int left, right;
    left = 2*root;               //left = 2*i    right = 2*i + 1     parent = i/2
    right = left +1;
}

int delete_min(int arr[], int n)
{
    int x;
    if(n==0) return 0; //error              if array inputs zero elem
    x = arr[1];           //assign value of root to first idex h[1]
    arr[1] = arr[n];        //override root value with last index value, and perc down
    //perc_down(        //not implemented
    return x;           

}
int main()
{
    int arr1[11];
    //populate array
    for (int y = 1; y<= 11; y++){
        if(10%y == 0){
        arr1[y] = y*2;
        }else{
            arr1[y] = y*100;
        }
    }
  
    //menu
    cout << "HEAP MENU OPTIONS: \n";
    cout << "1) build heap \n";
    cout << "2) printout heap/array \n";
    cout << "3) min_idx? \n";
    cout << "4) regenerate array\n";
    cout << "5) contains target\n";
    cout << "6) quit\n";

    int input;
    while(input!=-999)      //loops through switch untill quit is init.
    {
        cout << "> ";
        cin >> input;

        switch(input)
        {
            case 1 :   
                        td_build_heap(arr1, 11);
                        break;
            case 2 : 
                        for (int z = 1; z <= 11; z++){
                            cout << arr1[z] << " ";
                        }
                        break;
            case 3 : 
                        min_child_idx(arr1, 1, 11);
                        break;
            case 4 :
                        for (int y = 1; y<= 11; y++){
                            if(arr1[y] < arr1[y+2]){
                            arr1[y] = y*2;
                            }else{
                                arr1[y] = y/2;
                            }
                        }                       
                        break;
            case 5 :    
                        
                        break;
            case 6 : 
                        input = -999;
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
                        break;
        }
    cout << "\n";
    }   
return 0;
}