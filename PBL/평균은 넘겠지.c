#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int case1;			
	int num;			
			
	printf("��� �� �Է� : ");    // ����� ��� �� ����� ���� ����.
	scanf_s("%d", &case1);          
	for (int i = 0; i < case1; i++) {
		int grade[1000];					
		int total = 0;
		double aver;

		printf("�л� �� �Է� : ");		//������ �Է� �� �л� ���� �Է�.		
		scanf_s("%d", &num);
		for (int j = 0; j < num; j++) {	// �Է��� �� ��ŭ for ��
			scanf_s("%d", &grade[j]);
			total += grade[j];      //�Է��� ������ total�� �� ����.
		}
		aver = total / num;			//����� ����.

		int best = 0;

		for (int j = 0; j < num; j++) {
			if (grade[j] > aver) {			// �Է��� �л� �� �� ����� �Ѵ´ٸ�,
				best++;						// best ���� 1�� ����.
			}
		}
		printf("��� �̻� : %.3f%%\n", (double)best / num * 100); // ��� �̻��� �л����� ������ ���� ���.
	}
}
