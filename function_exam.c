#include <stdio.h>
double average(int arr[], int length) {
	int i;
	int result = 0; 
	
	for (i = 0; i < length; i++) {
		result += arr[i];
		
	}

	result = (result/length);
	return result;
}

int main(){
	
	double my_avg;
	int i;
	int arr[4];
	int length = sizeof(arr) / sizeof(int);

	for (i = 0; i < 4; i++) {
		printf("국어 > 수학 > 영어 > 과학 순서로 점수를 입력하세요. : ");
		scanf("%f1", &arr[i]);
	}
	
	my_avg = average(arr, length);

	printf("점수 평균 : %.1\n", my_avg);

	return 0;
}
