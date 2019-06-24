#include <stdio.h>

int __cdecl cdecl_Test(int a, int b){
	int result = 0;
	result = a+b;
	return result;
}

int main(int argc, char * argv[]) {
	cdecl_Test(1,2);

	return 0;
}
