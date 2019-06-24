#include <stdio.h>

union myInfo
{
	char bloodType;
	int age;
};

int main()
{
	union myInfo myU;
	union myInfo yourU = {'B'};

	myU.bloodType = 'A';

	printf("myU.bloodType = %c, myU.age = %d\n", myU.bloodType, myU.age);
	printf("yourU.bloodType = %c, yourU.age = %d\n", yourU.bloodType, yourU.age);

	return 0;
}
