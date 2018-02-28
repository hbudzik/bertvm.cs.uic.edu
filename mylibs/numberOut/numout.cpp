#include <iostream>
#include <ctime>

using namespace std;

/* this program will generate positive integers 
 * n is number of randomly created number user wants
 */

int main(){

int data;

cout << "enter how much data n: ";
cin >> data;
cout << endl;

int x;				//variable to be printed
srand(time(0));			//makes numbers be random each time

for (int n=0; n<data; n++){
    x = rand() % 100 + 1;	//assigns random number to x

     if(n%50 == 0)		//every two numbers skip a line
    {
        cout << endl;
    }

    cout << x << "\t";		//prints that number

   
}

}
