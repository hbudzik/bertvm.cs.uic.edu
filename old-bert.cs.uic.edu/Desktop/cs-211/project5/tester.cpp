#include <iostream>
using namespace std;


class bo
{
	private:
		int size;
	
	public:
	bo()
	{
		printf("will get printed automagically");
		size = 1;
	}
	
	void setSize(int x)
		{
			size = x;
		}
		
	int getSize()
		{
			return size;
		}
		
	
};

int main()
{
	bo stack;
	for (int i=0; i < 3; i++)
	{
	stack.setSize(i);
	printf("\nsize: %i", stack.getSize());
}

	return 0;
	
	
	
}
