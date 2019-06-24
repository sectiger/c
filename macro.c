#include <stdio.h>
#include <stdint.h>

/* volatile example */
#define UART_CR0	(*(volatile unsigned int *) 0x7EF80000)

/* example for macro function */
#define SUM(a,b)	((a)+(b))
#define MUL(a,b)	((a)*(b))
#define MUL2(a,b)	a*b

#define DEBUG_PREFIX	"PREFIX"
#define DEBUG(msg,...) fprintf(stderr, DEBUG_PREFIX "[%s %s() line:%d] " msg "\n", \
		__FILE__, __func__, __LINE__, ##__VA_ARGS__)

/* example typedef uses case */
typedef signed char s8_t;
typedef unsigned char u8_t;

typedef signed short s16_t;
typedef unsigned short u16_t;

typedef signed int s32_t;
typedef unsigned int u32_t;

typedef signed long s64_t;
typedef unsigned long u64_t;

void test()
{
	DEBUG("test function call!\n");
}

int main(int argc, char *argv[])
{
	int a = 2;

	s8_t one = 1;
	u16_t two = 2;

	printf("s8_t size %lu\n", sizeof(s8_t));
	printf("u16_t size %lu\n", sizeof(u16_t));
	printf("u32_t size %lu\n", sizeof(u32_t));
	printf("u64_t size %lu\n", sizeof(u64_t));

	printf("int64_t size %lu\n", sizeof(int64_t));		// need include stdint.h

	for(int i = 0; i < argc; ++i) {
		DEBUG("%d. %s [%08X]\n", i, argv[i], argv[i]);
	}

	DEBUG("a = %d\n", SUM(a, 2));
	DEBUG("a = %d\n", MUL2(3+1, 3+1));

	test();

	return 0;
}
