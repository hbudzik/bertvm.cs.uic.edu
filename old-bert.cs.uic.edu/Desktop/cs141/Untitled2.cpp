#include <iostream>

using namespace std;

struct NODE{
	char data = 'a';
	struct NODE * pNext;
};

int main()
{

	NODE *pHead = new NODE;
	NODE *pTemp = new NODE;
	
	for (int i='a'; i < 'f'; i++){
		
		if(i == 'c'){
			pTemp->data = 'X';
			cout << pTemp->data << endl;
		}
		cout << pHead->data << endl;
		pHead->data
	}
	
	

	

	
	

return 0;
}
