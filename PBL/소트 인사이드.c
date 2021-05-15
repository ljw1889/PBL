#include <stdio.h>
#include <string.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main() {
	char N[5] = { NULL };  //배열을 생성한다.
	int tmp;
	gets(N);   //배열에 넣을 숫자를 입력한다
	for (int i = 0; i < strlen(N) - 1; i++) {
		for (int j = i; j < strlen(N); j++) {
			if (N[i] < N[j]) {
				SWAP(N[i], N[j], tmp); //크기를 비교해 순서를 바꾼다.
			}
		}
	}
	puts(N);  //배열 a를 출력한다
	return 0;
}
