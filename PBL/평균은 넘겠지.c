#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int case1;			
	int num;			
			
	printf("경우 수 입력 : ");    // 평균을 계산 할 경우의 수를 구함.
	scanf_s("%d", &case1);          
	for (int i = 0; i < case1; i++) {
		int grade[1000];					
		int total = 0;
		double aver;

		printf("학생 수 입력 : ");		//성적이 입력 될 학생 수를 입력.		
		scanf_s("%d", &num);
		for (int j = 0; j < num; j++) {	// 입력한 수 만큼 for 문
			scanf_s("%d", &grade[j]);
			total += grade[j];      //입력한 성적을 total에 다 더함.
		}
		aver = total / num;			//평균을 구함.

		int best = 0;

		for (int j = 0; j < num; j++) {
			if (grade[j] > aver) {			// 입력한 학생 들 중 평균을 넘는다면,
				best++;						// best 값을 1씩 증가.
			}
		}
		printf("평균 이상 : %.3f%%\n", (double)best / num * 100); // 평균 이상인 학생들을 계산식을 통해 계산.
	}
}
