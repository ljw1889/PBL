#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {
	if (n <= 1)   //���� n�� 1�Ǵ� 0�̸� n�� return�Ѵ�
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);  //�׷��� ������ n-1,n-2���� ���� return�Ѵ�.
}
int main() {
	int x;
	scanf("%d", &x);
	printf("%d", fibo(x));
}
