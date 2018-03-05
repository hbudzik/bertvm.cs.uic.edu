#include <iostream>
#include <ctime>	// for srand seed
#include <cstdlib> // for strtoi  string to integer convertion


using namespace std;


/* this program will generate positive integers 
 * n is number of randomly created number user wants
 */

int main(int argc, char** argv){

if ( (argc == 1) || (argv[1][0] != '-'))
	{
			cout 	<< "use:\t./hubert-randnumbers -n <value> -d -h"					<< endl << endl
					<< "\t-n value	\t--value = number of randomly generated numbers" 	<< endl
					<< "\t-d			--debugg mode" 									<< endl;	
			return 0;
		
	}

int n;
for(int z=1; z < argc; z++)
{	
	if (argv[z][1] == 'h') {
			cout 	<< "use:\t./hubert-randnumbers -n <value> -d -h"					<< endl << endl
					<< "\t-n value	\t--value = number of randomly generated numbers" 	<< endl
					<< "\t-d			--debugg mode" 									<< endl;	
			return 0;
	} else if ( argv[z][1] == 'd' ) {
			cout << "Debuff mode on " << endl;	
			return 0;
	} else if ( argv[z][1] == 'n' ) {
			n = atoi ( argv[z+1] );			
			break;						//exit for loop		
	} else {
		cout << "bad parameters.. try again or try '-h'" << endl;
		return 0;
	}
	
}

int x;
srand(time(0));			//makes numbers be random each time

for (int i=0; i<n; i++)
{
    x = rand() % 1000 + 1;	//assigns random number to x

     if(i%10 == 0)		//every two numbers skip a line
    {
        cout << endl;
    }

    cout << x << "\t";		//prints that number

}
cout << "-999"; //adds -999 to the end of list, used as stop signal for other apps
cout << endl;

return 0;
}
