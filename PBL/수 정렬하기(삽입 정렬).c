#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, tmp, i, j;
	int num[20] = { NULL }; //�迭�� �����Ѵ�
	scanf("%d", &n);
	for (i = 0; i < n; i++) //�Է��� ���� �迭�� �ִ´�
		scanf("%d", &num[i]);
	for (i = 1; i < n; i++) {
		tmp = num[i];
		for (j = i - 1; j >= 0 && num[j] > tmp; j--)  //�����Ͱ� �߰��� ������ �迭�� index�� �����Ѵ�(��������)
			num[j + 1] = num[j];
		num[j + 1] = tmp;
	}
	for (int i = 0; i < n; i++)  //�迭�� ����Ѵ�
		printf("%d\n", num[i]);
	return 0;
}