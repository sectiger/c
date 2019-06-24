#include <stdio.h>
#include <string.h>

typedef union _BOX {
	short candy;
	int snack;
	char doll[8];
} BOX;

typedef struct _BIT {
	unsigned char gpio0	:	1;
	unsigned char gpio1	:	1;
	unsigned char gpio2	:	1;
	unsigned char gpio3	:	1;
	unsigned char gpio4	:	1;
	unsigned char gpio5	:	1;
	unsigned char gpio6	:	1;
	unsigned char gpio7	:	1;
} BIT;

typedef struct _USART_CR1 {
	union {    // 익명 공용체
		struct {    // 익명 구조체
			unsigned int SBK		: 1;	//0
			unsigned int RWU		: 1;
			unsigned int RE			: 1;
			unsigned int TE			: 1;
			unsigned int IDLEIE		: 1;	//4
			unsigned int RXNEIE		: 1;
			unsigned int TCIE		: 1;
			unsigned int TXEIE		: 1;
			unsigned int PEIE		: 1;	//8
			unsigned int PS			: 1;
			unsigned int PCE		: 1;
			unsigned int WAKE		: 1;
			unsigned int M			: 1;	//12
			unsigned int UE			: 1;
			unsigned int RESERVED	: 18;
		};
		unsigned int value;
	};
} USART_CR1;

enum USART_CR1_UE_VALUE {
	USART_CR1_UE_DISABLE,
	USART_CR1_UE_ENABLE
};

enum USART_CR1_M_BITS {
	USART_CR1_M_8BIT,
	USART_CR1_M_9BIT
};

enum TEST_VALUE {
	TEST_VALUE_A	= 15,
	TEST_VALUE_B,
	TEST_VALUE_C	= 99,
	TEST_VALUE_D,
	TEST_VALUE_E	= -1,
	TEST_VALUE_F
};

int main()
{
	BOX box = {};

	box.candy = 2;
	printf("box 0x%08X\n", box);
	box.snack = 0x44;
	printf("box 0x%08X\n", box);
	strncpy(box.doll, "aaaaaaaa", 8);
	printf("box 0x%08X\n", box);

	BIT bit;

	bit.gpio0 = 0;
	bit.gpio1 = 1;
	bit.gpio2 = 0;
	bit.gpio3 = 1;
	bit.gpio4 = 0;
	bit.gpio5 = 1;
	bit.gpio6 = 0;
	bit.gpio7 = 1;
	printf("bit %02X\n", bit);

	USART_CR1 ucr1 = {};	

	printf("ucr1 0x%08X\n", ucr1.value);
	ucr1.UE	= USART_CR1_UE_ENABLE;
	ucr1.M	= USART_CR1_M_8BIT;
	printf("ucr1 0x%08X\n", ucr1.value);


	printf("TEST_VALUE_A %d\n", (int)TEST_VALUE_A);
	printf("TEST_VALUE_B %d\n", (int)TEST_VALUE_B);
	printf("TEST_VALUE_C %d\n", (int)TEST_VALUE_C);
	printf("TEST_VALUE_D %d\n", (int)TEST_VALUE_D);
	printf("TEST_VALUE_E %d\n", (int)TEST_VALUE_E);
	printf("TEST_VALUE_F %d\n", (int)TEST_VALUE_F);

	return 0;
}
