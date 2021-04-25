#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int arr[9] = { 3, 29, 38, 12, 57, 74, 40, 85, 61 };

	int MAX = arr[0];  // 임의로 MAX 값을 배열의 가장 처음 부분으로 할당함.

	for (int i = 0; i < 9; i++) {  // 배열의 크기 만큼 반복문을 돌림.
		if (arr[i] > MAX) {		// MAX 값보다 다음 배열의 값이 크다면,
			MAX = arr[i];			// MAX 값에 새로 할당함.
		}
		else {
			MAX = MAX;
		}
	}
	printf("%d", MAX);			// 반복문 을 빠져 나와, MAX 에 할당 된 수가 최댓값이 됨.

	return 0;
}
