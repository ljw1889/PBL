#include<stdio.h>
#include<math.h>

void hanoi(int n, char a, char b, char c) { //a ������ c������ ���� b ���� Ȱ���Ͽ� ���� �Լ���.

	if (n == 1) {
		printf("%c %c\n", a, c);
	}
	else {
		hanoi(n - 1, a, c, b); //��͸� Ȱ���Ͽ�, ���� ���� 1�� �ƴ� �� �̵��ϴ� Ȱ�� ���� ��ġ�� �ٲپ� �̵��ϰ� ��.
		printf("%c %c\n", a, c);
		hanoi(n - 1, b, a, c);//��͸� Ȱ���Ͽ�, ���� ���� 1�� �ƴ� �� �̵��ϴ� Ȱ�� ���� ��ġ�� �ٲپ� �̵��ϰ� ��.
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int num = pow(2, n) - 1;
	printf("%d\n", num);
	hanoi(n, '1', '2', '3');

	return 0;
}
