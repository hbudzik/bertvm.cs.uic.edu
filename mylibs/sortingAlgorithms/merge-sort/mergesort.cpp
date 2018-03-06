#include <iostream>

using namespace std;

bool DEBUFF = false;

int main(int argc, char** argv)
{

// setting flags input 
if ( argc == 1 )
{
	cout 	<< "USE: \tmergesort [OPTIONS]...   < input" << endl;
	cout 	<< "\t-input \t-- unsorted list on elements" << endl;
	cout 	<< "Options:" << endl;
	cout    << "\t-h	\t-- help info"	<< endl;
        cout    << "\t-d	\t-- debugg mode"	<< endl;
        return 0;
}

for (int z = 1; z < argc; z++)
{
	if ( argv[z][0] != '-' ) { 
		cout << "wrong input .. gry -h for help.. " << endl;
		return 0;
	}else if ( argv[z][1] == 'h' ) {
		cout << "prints out -h info help info " << endl;
		continue;
	}else if ( argv[z][1] == 'd' ) {
		cout << "DBUGG MODE: ON " << endl;
		DEBUFF = true;
		continue;
	}else{
		cout << "-" << argv[z][1] << " is not recognized parameter " << endl;
		return 0;
	}
}


return 0;
}
