#include <stdio.h>

int main ()
{ 
	int values[10] = {10,9,8,7,6,5,4,3,2,1};

	int stack[100];
	int top = 0;

	for(int i = 0; i < sizeof(values)/sizeof(int); i++)
	{
		stack[top++] = values[i];
	}

	for (int i = 0; i < sizeof(values)/sizeof(int); i++)
	{
		printf("%d", stack[--top]);
	}
	printf("\n");

	return 0;
}
