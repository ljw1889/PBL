#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, tmp, i, j;
	int num[20] = { NULL }; //배열을 생성한다
	scanf("%d", &n);
	for (i = 0; i < n; i++) //입력한 값을 배열에 넣는다
		scanf("%d", &num[i]);
	for (i = 1; i < n; i++) {
		tmp = num[i];
		for (j = i - 1; j >= 0 && num[j] > tmp; j--)  //데이터가 추가될 때마다 배열의 index가 증가한다(삽입정렬)
			num[j + 1] = num[j];
		num[j + 1] = tmp;
	}
	for (int i = 0; i < n; i++)  //배열을 출력한다
		printf("%d\n", num[i]);
	return 0;
}