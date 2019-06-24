#include <stdio.h>

struct BF
{
	unsigned int sex: 1;
	unsigned int grade: 3;
	unsigned int room: 4;
};

int main()
{
	struct BF bitfield;
	int s;
	int g;
	int r;

	printf("정보입력 (sex, grade, room)\n");
	scanf("%d %d %d\n", &s, &g, &r);

	bitfield.sex = s;
	bitfield.grade = g;
	bitfield.room = r;

	if(bitfield.sex){
		printf("남성 : %d학년 %d반\n", g, r);
	}
	else
	{
		printf("여성 : %d학년 %d반\n", bitfield.grade, bitfield.room);
	}
	return 0;
}

