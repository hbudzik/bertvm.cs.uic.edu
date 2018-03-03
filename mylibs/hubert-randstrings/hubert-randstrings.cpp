#include <iostream>
#include <string>
#include <ctime>
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
	
if ( (argc == 1) || (argv[1][0] != '-'))
	{
		cout 	<< "use:\t./hubert-randstrings -n <value> -l <value> -d -h"						<< endl << endl
					<< "\t-n value	\t--value = number of randomly generated strings" 	<< endl
					<< "\t-d			--debugg mode" 									<< endl
					<< "\t-l value	\t--value = length of string to be generated"		<< endl;
		return 0;
	}

int n = 0, l = 0;
for(int z=1; z < argc; z++)
{	
	if (argv[z][1] == 'h') {
			cout 	<< "use:\t./hubert-randstrings -n <value> -l <value> -d -h"					<< endl << endl
					<< "\t-n value	\t--value = number of randomly generated strings" 	<< endl
					<< "\t-d			--debugg mode" 									<< endl
					<< "\t-l value	\t--value = length of string to be generated"		<< endl;	
			return 0;
	} else if ( argv[z][1] == 'd' ) {
			cout << "Debuff mode on " << endl;	
			return 0;
	} else if ( argv[z][1] == 'n' ) {
			n = atoi ( argv[z+1] );			
			//break;						//exit for loop		
	} else if ( argv[z][1] == 'l' ) {
			l = atoi ( argv[z+1] );			
			//break;						//exit for loop		
	}
}

	string charOut;
	srand(time(0));	//random seed

	//output
	for (int j=0; j < n; j++)
	{

		for (int i = 0; i < l; i++)
		{
			charOut += getRandomChar();
				//picks one char from pool[] randomly and attaches it to the end of charOut which will be printed out as a whole  
		}

		//ends line every 2 string 
		if (j%2 == 0){
			cout << endl;
		}
		
		cout << charOut << " ";
		charOut = "";			//resets the string so it wont concatenate 
	}

	//adds ending symbol
	cout << endl << "END" << endl;
	return 0;
}
