#include <iostream>

using namespace std;

struct node{
	int val;
	struct node* next;
};


node **question1(int n)
{
	node** arr = new node* [n];


	for (int i=0; i < n; i++)
	{
		arr[i] = new node;
		arr[i]->val = i;
		arr[i]->next = nullptr;	
	} 


return arr;
}


int main ()
{

int n= 5;
node** newarr;
newarr = question1(n);


for (int i=0; i < n; i++)
{
	cout <<"arr[" << i << "]: " << newarr[i]->val << endl;
}

return 0;
}
