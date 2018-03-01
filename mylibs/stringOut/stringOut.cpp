#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

//our pool of characters to generate from
static const char pool[] = "abcdefghijklmnopqrstuvwxyz"
		  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		  "1234567890";

int poolSize = sizeof(pool) -1;

//this function will return a random character from pool
char getRandomChar()
{
	return pool[rand() % poolSize];
}

int main(int argc, char *argv[])
{
	
	int stringLength;
	int numString;
	string charOut;
	srand(time(0));	//random seed

	cout << "length of randomly generated string:  ";
	cin >> stringLength;
	cout << endl << "how many strings to be generated: ";
	cin >> numString;
	cout << endl;
	
	//output
	for (int j=0; j < numString; j++)
	{
		for (int i = 0; i < stringLength; i++)
		{
			charOut += getRandomChar();
				//picks one char from pool[] randomly and attaches it to the end of charOut which will be printed out as a whole  
		}
	cout << charOut << endl;
	charOut = "";			//resets the string so it wont concatenate 
	}

	return 0;
}
