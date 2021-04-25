#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char input[100];
	scanf("%s", input);			// 회문을 판별 할 문자배열을 받음.
	int length = strlen(input);   // 입력한 문자열의 크기를 lenth 에 할당함.

	int result = 1;

	for (int i = 0; i < (length / 2); i++) { // 입력받은 것에 /2 만큼 반복문 진행, 이유는
		if (input[i] != input[length - 1 - i]) {   // 양 끝에서부터 값을 비교하여 가운데 까지 도달하게 함.
			result = 0;			  	
		}
	}
	if (result == 1) {
		printf("회문이다");				// result 가 1 로 유지될 시 회문으로 판별.
	}
	else {
		printf("회문 아니다.");			// 0으로 바뀌면 회문이 아닌 것 으로 판별.
	}
}
