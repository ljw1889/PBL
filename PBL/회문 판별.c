#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char input[100];
	scanf("%s", input);			// ȸ���� �Ǻ� �� ���ڹ迭�� ����.
	int length = strlen(input);   // �Է��� ���ڿ��� ũ�⸦ lenth �� �Ҵ���.

	int result = 1;

	for (int i = 0; i < (length / 2); i++) { // �Է¹��� �Ϳ� /2 ��ŭ �ݺ��� ����, ������
		if (input[i] != input[length - 1 - i]) {   // �� ���������� ���� ���Ͽ� ��� ���� �����ϰ� ��.
			result = 0;			  	
		}
	}
	if (result == 1) {
		printf("ȸ���̴�");				// result �� 1 �� ������ �� ȸ������ �Ǻ�.
	}
	else {
		printf("ȸ�� �ƴϴ�.");			// 0���� �ٲ�� ȸ���� �ƴ� �� ���� �Ǻ�.
	}
}
