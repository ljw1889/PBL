#include <stdio.h>
#include <string.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	char N[5] = { NULL };  //�迭�� �����Ѵ�.
	int tmp;
	gets(N);   //�迭�� ���� ���ڸ� �Է��Ѵ�
	for (int i = 0; i < strlen(N) - 1; i++) {
		for (int j = i; j < strlen(N); j++) {
			if (N[i] < N[j]) {
				SWAP(N[i], N[j], tmp); //ũ�⸦ ���� ������ �ٲ۴�.
			}
		}
	}
	puts(N);  //�迭 a�� ����Ѵ�
	return 0;
}
