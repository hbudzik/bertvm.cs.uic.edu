#include <iostream>

using namespace std;


//prints out the list
void arrayPrint (int *arr)
{
	int i = 0;
	while(arr[i] != -999)
	{ 
	cout << arr[i++] << " ";
	}
	cout << endl;
return;
}


//populates the array dynamically 
void arrayPopulate(int *arr)
{
int x = 0; //index for array
cin >> arr[x];
while(arr[x] != -999)
	{	
		x++;
		cin >> arr[x];
	}
}


//sorts array using insert sort method
void isort(int *arr) 
{
   int i, j, x;
   while(arr[i] != -999)
   {
	x = arr[i];
	j = i-1;
	
	while(j>=0 && x < arr[j]){
	   arr[j+1] = arr[j];
	   j--;
	}
   	// now x belongs in slot j+1
	arr[j+1] = x;
	i++;
   }
return;
}

int main(int argc, char **argv)
{
int n = 10;
int *arr = new int[n];

//populate the array
arrayPopulate(arr);

//prints out the array
arrayPrint(arr);

return 0;
}
