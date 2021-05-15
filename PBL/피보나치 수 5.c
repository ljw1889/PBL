#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {
	if (n <= 1)   //만약 n이 1또는 0이면 n을 return한다
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);  //그렇지 않으면 n-1,n-2항의 합을 return한다.
}
int main() {
	int x;
	scanf("%d", &x);
	printf("%d", fibo(x));
}
