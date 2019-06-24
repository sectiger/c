#include <stdio.h>

const int check = 1;

int main(int argc, char *argv[]){
	if ((*(char*)&check) == 0)
		printf("Big-endian !\n");
	else
		printf("Little-endian !\n");

	return 0;

}
