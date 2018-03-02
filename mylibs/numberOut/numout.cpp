#include <iostream>
#include <ctime>
#include <cstdlib> // for strtoi  string to integer convertion


using namespace std;


/* this program will generate positive integers 
 * n is number of randomly created number user wants
 */

int main(int argc, char** argv){


int n;

for(int z=2; z <= argc; z++)
{	
	if (argv[z][0] != '-'){
		cout << "not a FLAG" << endl;
		return 0;
	}else{
		if (argv[z][1] == "h"){
		cout << "prints out help info" << endl;	
		
		}else if (argv[z][1] == "n"){
			n = atoi(argv[z+1];
		}
	}
}


if (argc < 3){
	cout << "error use -help for flags" << endl;
	return 0;
}else if(argv[1][0] == '-'){
	n = atoi(argv[2]);	
	cout << "number of values: " << n << endl;
}else if (argv[1][1] == 'h'){
	cout << "prints out help info" << endl;
}
return 0;
int x;
srand(time(0));			//makes numbers be random each time

for (int i=0; i<n; i++)
{
    x = rand() % 100 + 1;	//assigns random number to x

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
