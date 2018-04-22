#include <iostream>

using namespace std;


int main()
{
//menu
    cout << "MENU OPTIONS: \n";
    cout << "1) print \n";
    cout << "2) min/max \n";
    cout << "3) insert \n";
    cout << "4) delete(not implemented\n";
    cout << "5) quit\n";

    int input;
    while(input!=-999)      //loops through switch untill quit is init.
    {
        cout << "choose option: ";
        cin >> input;

        switch(input)
        {
            case 1 : 
                        cout << "option 1";
                        break;
            case 2 : 
                    cout << "option 2";
                    break;
            case 3 : 
                        cout << "option 3";
                        break;
            case 4 : 
                        cout << "option 4";
                        break;
            case 5 : 
                        cout << "quitting";
                        input = -999; //breaks from while loop
                        break;
            default : 
                        cout << "wrong input";
        }
    cout << "\n";
    }

    return 0;
}