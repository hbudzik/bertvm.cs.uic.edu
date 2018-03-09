#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> list(1);	

//prints out the vectobreak;
cout << "vector.size(1): " << list.size() << endl;
cout << "vector.resize() \n";
list.resize(10);
cout << "vector.size(): " << list.size() << endl;

//prints out vector
for (int i = 0; i < list.size(); i++)
{
	list[i] = i *  10;
	cout << "vector[" << i << "]: " << list[i] << endl;
}

return 0;
}
