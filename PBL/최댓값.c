#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int arr[9] = { 3, 29, 38, 12, 57, 74, 40, 85, 61 };

	int MAX = arr[0];  // ���Ƿ� MAX ���� �迭�� ���� ó�� �κ����� �Ҵ���.

	for (int i = 0; i < 9; i++) {  // �迭�� ũ�� ��ŭ �ݺ����� ����.
		if (arr[i] > MAX) {		// MAX ������ ���� �迭�� ���� ũ�ٸ�,
			MAX = arr[i];			// MAX ���� ���� �Ҵ���.
		}
		else {
			MAX = MAX;
		}
	}
	printf("%d", MAX);			// �ݺ��� �� ���� ����, MAX �� �Ҵ� �� ���� �ִ��� ��.

	return 0;
}
