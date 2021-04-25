#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main() {
	double input[10];
	double total = 0;
	double aver = 0;

	for (int i = 0; i < 10; i++) {
		printf("입력하시오 : ");
		scanf_s("%lf", &input[i]);   //10번의 실수를 입력하게 함.

		total += input[i];				// 10개의 실수를 모두 더한 값을 total 에 할당.
	}
	aver = total / 10;					// 평균은 total/10 을 하여 구함.
	printf("평균 %lf\n", aver);

	double total2 = 0;

	for (int j = 0; j < 10; j++) {
		total2 += (input[j] - aver) * (input[j] - aver); //표준편차를 구하기 위해 분산 식을 적용함.
	}
	double bs = total2 / 10;		// 마찬가지로 분산식을 적용함.
	printf("표준 편차는 : %lf", sqrt(bs));			//마지막에 표준 편차를 구하기 위해 루트를 씌우는 함수 sqrt() 를 사용함.
}
