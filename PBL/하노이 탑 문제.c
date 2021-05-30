#include<stdio.h>
#include<math.h>

void hanoi(int n, char a, char b, char c) { //a 봉에서 c봉으로 가되 b 봉을 활용하여 가는 함수임.

	if (n == 1) {
		printf("%c %c\n", a, c);
	}
	else {
		hanoi(n - 1, a, c, b); //재귀를 활용하여, 남은 링이 1이 아닐 때 이동하는 활용 봉의 위치를 바꾸어 이동하게 함.
		printf("%c %c\n", a, c);
		hanoi(n - 1, b, a, c);//재귀를 활용하여, 남은 링이 1이 아닐 때 이동하는 활용 봉의 위치를 바꾸어 이동하게 함.
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
