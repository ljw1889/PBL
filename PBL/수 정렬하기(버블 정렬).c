#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	int n, tmp;
	int num[20]; //�迭�� �����Ѵ�
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  //�Է��� ���� �迭�� �ִ´�
		scanf("%d", &num[i]);
	for (int i = n - 1; i > 0; i--) { //�迭�� ��,�� �ε����� ���ڿ� ���� �� ũ�⿡ ���� �ٲ۴�(��������)
		for (int j = 0; j < i; j++) {
			if (num[j] > num[j + 1])
				SWAP(num[j], num[j + 1], tmp);
		}
	}
	for (int i = 0; i < n; i++) //�迭�� ����Ѵ�
		printf("%d\n", num[i]);
	return 0;
}
