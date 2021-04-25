#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int a, b, c;				// 입력받을 숫자를 생성.
	int result;
	int remain;					
	int i;				
	int num[10] = { 0,0,0,0,0,0,0,0,0,0 };		//각 자리 수 마다 얼마나 사용 되었는지를 보기 위해, 0으로 할당.

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);

	result = a * b * c;				// 입력 받은 숫자를 곱함
	printf("A * B * C = %d\n", result);

	while (result > 0) {
		remain = result % 10;		//10의 자리 숫자 마다 놔눠서 각 자리수에 사용된 수를 봄.
		result = result / 10;
		num[remain]++;				// 결국엔 나눈 숫자 부분이 사용 된 것이기에 그숫자부분의 엘리먼트를 증가 시켜서 확인함.
	}

	for (i = 0; i < 10; i++) {
		printf("%d\n", num[i]);		//각 자리수에 얼마나 사용되었는지를 출력함. 
	}
}
