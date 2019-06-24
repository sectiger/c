#include <stdio.h>

union {
	unsigned int bits32;
	unsigned char bytes[4];
} theValue;

int main(int argc, char *argv[]){
	theValue.bits32 = 1;

	if ( theValue.bytes[0] == 0)
		printf("Big-endian !\n");
	else
		printf("Little-endian !\n");
	return 0;

}

