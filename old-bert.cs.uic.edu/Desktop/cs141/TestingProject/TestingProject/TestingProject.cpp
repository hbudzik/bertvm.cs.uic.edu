#include <stdio.h>
#include <string.h>


int main()
{
	char stringOne[100] = "hey there";
	printf_s("Enter string here: ");
	scanf_s(" %s", &stringOne);
	printf_s("\nyou entered: ---> %s", stringOne);

	getchar();
	return 0;
}