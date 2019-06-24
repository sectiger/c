#include <stdio.h>

int main () {
	
	printf("hello world\n");
	printf("hello %%7d world %7d\n", 123);
	printf("hello %%+7d world %+7d\n", 123);
	printf("hello %%-7d world %-7d\n", 123);

	printf("hello %%7f world %7f\n", 123.456);
	printf("hello %%+7.2f world %+7.2f\n", 123.456);
	printf("hello %%-7.3f world %-7.3f\n", 123.456);
	printf("hello %%7.5f world %7.5f\n", 123.456);
	return 0;
}

