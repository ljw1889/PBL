#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	int n, tmp, min;
	int num[20]; //배열을 생성한다
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  //입력한 값을 배열에 넣는다
		scanf("%d", &num[i]);
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) { //배열의 0번째 index부터 시작하여 최솟값을 찾고 크기에 따라 index를 바꾼다(선택정렬)
			if (num[j] < num[min])
				min = j;
			SWAP(num[i], num[min], tmp);
		}
	}
	for (int i = 0; i < n; i++) //배열을 출력한다
		printf("%d\n", num[i]);
	return 0;
}