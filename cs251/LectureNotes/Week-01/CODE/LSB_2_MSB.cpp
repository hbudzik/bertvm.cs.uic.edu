#include <iostream>

// here we will turn base-10 number into binary and print it out LSB first then use recursion and print MSB first

using namespace std;

//converts base-10 and prints it out LSB first
void convertLSB(int x);

//converts base10 and prints it out MSB first, uses recursion 
void convertMSB(int x);

int main () {

    unsigned int x;

    printf("Enter number (base-10):\t ");
    scanf("%i", &x);

    cout << endl << "base-10:\t " << x;
    cout << endl << "binary LSB first: \t";

    // Converts variable value to binary and prints it out LSB first( not useful)
    convertLSB(x);        

    cout << endl << "binary MSB first: \t";
    // Converts variable value to binary and prints it out MSB first recursivly( usefull)
    convertMSB(x);
}

void convertLSB(int x)
{
    unsigned int bit;

    do {
        bit = x % 2;    // assigns either 0 or 1 to bit variable, x % 2 will produce 1 if theres a reminder, 0 if no reminder once divided by two
        cout << bit;    // prints out the bit

        /*
            // another way to print out bits is using 
            if (bit == 0)   putchar('0');
            else            putchar('1');

            // more clever way of printing using ASCI '0' + 0 = 0, and '0' + 1 =1;
            putchar('0' +bit);
        */          
        x = x/2;        // shifts off lsb(least significant bit)
    } while ( x > 0);
}

void convertMSB(int x)
{
unsigned int bit;

    //base case
    if (x == 0)
        return;
    bit = x % 2;    // assigns either 0 or 1 to bit variable, x % 2 will produce 1 if theres a reminder, 0 if no reminder once divided by two

    convertMSB(x/2);        // RECURSION
    cout << bit;     // Print LSB after recursion!

    return;
}