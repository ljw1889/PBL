#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	int n, tmp;
	int num[20]; //배열을 생성한다
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  //입력한 값을 배열에 넣는다
		scanf("%d", &num[i]);
	for (int i = n - 1; i > 0; i--) { //배열의 앞,뒤 인덱스의 숫자와 비교한 후 크기에 따라 바꾼다(버블정렬)
		for (int j = 0; j < i; j++) {
			if (num[j] > num[j + 1])
				SWAP(num[j], num[j + 1], tmp);
		}
	}
	for (int i = 0; i < n; i++) //배열을 출력한다
		printf("%d\n", num[i]);
	return 0;
}
