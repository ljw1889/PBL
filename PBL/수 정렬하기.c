#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	int n, tmp, min;
	int num[20]; //�迭�� �����Ѵ�
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  //�Է��� ���� �迭�� �ִ´�
		scanf("%d", &num[i]);
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) { //�迭�� 0��° index���� �����Ͽ� �ּڰ��� ã�� ũ�⿡ ���� index�� �ٲ۴�(��������)
			if (num[j] < num[min])
				min = j;
			SWAP(num[i], num[min], tmp);
		}
	}
	for (int i = 0; i < n; i++) //�迭�� ����Ѵ�
		printf("%d\n", num[i]);
	return 0;
}