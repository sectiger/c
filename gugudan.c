#include <stdio.h>

int main() {
	int i, j;

	for (i = 2; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			printf("%d * %d = %d\t", i, j, (i*j));
			if (j % 3 == 0) {
				printf("\n");
			}
			if(j == 9) {
				printf("\n"); 
			}	
		}
	}
	return 0;
}
