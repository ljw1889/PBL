#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main() {
	double input[10];
	double total = 0;
	double aver = 0;

	for (int i = 0; i < 10; i++) {
		printf("�Է��Ͻÿ� : ");
		scanf_s("%lf", &input[i]);   //10���� �Ǽ��� �Է��ϰ� ��.

		total += input[i];				// 10���� �Ǽ��� ��� ���� ���� total �� �Ҵ�.
	}
	aver = total / 10;					// ����� total/10 �� �Ͽ� ����.
	printf("��� %lf\n", aver);

	double total2 = 0;

	for (int j = 0; j < 10; j++) {
		total2 += (input[j] - aver) * (input[j] - aver); //ǥ�������� ���ϱ� ���� �л� ���� ������.
	}
	double bs = total2 / 10;		// ���������� �л���� ������.
	printf("ǥ�� ������ : %lf", sqrt(bs));			//�������� ǥ�� ������ ���ϱ� ���� ��Ʈ�� ����� �Լ� sqrt() �� �����.
}
