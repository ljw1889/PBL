#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int a, b, c;				// �Է¹��� ���ڸ� ����.
	int result;
	int remain;					
	int i;				
	int num[10] = { 0,0,0,0,0,0,0,0,0,0 };		//�� �ڸ� �� ���� �󸶳� ��� �Ǿ������� ���� ����, 0���� �Ҵ�.

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);

	result = a * b * c;				// �Է� ���� ���ڸ� ����
	printf("A * B * C = %d\n", result);

	while (result > 0) {
		remain = result % 10;		//10�� �ڸ� ���� ���� ������ �� �ڸ����� ���� ���� ��.
		result = result / 10;
		num[remain]++;				// �ᱹ�� ���� ���� �κ��� ��� �� ���̱⿡ �׼��ںκ��� ������Ʈ�� ���� ���Ѽ� Ȯ����.
	}

	for (i = 0; i < 10; i++) {
		printf("%d\n", num[i]);		//�� �ڸ����� �󸶳� ���Ǿ������� �����. 
	}
}
