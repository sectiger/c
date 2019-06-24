#include <stdio.h>

int main()
{
	int values[10] = {10,9,8,7,6,5,4,3,2,1};

	int queue[100];
	int head = 0, tail = 0;

	for(int i = 0; i < sizeof(values)/sizeof(int); i++)
	{
		queue[tail++] = values[i];
	}

	for(int i = 0; i < sizeof(values)/sizeof(int); i++)
	{
		printf("%d", queue[head++]);
	}
	printf("\n");

	return 0;
}
