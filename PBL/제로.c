#include <stdio.h>
#include <stdlib.h>
#define MAX 100	

int stack[MAX];				//본 프로그램에서는 스택을 하나만 쓸거라 전역변수로 생성	
int top = -1;
int r = 0;                   //나중 결과값을 위한 변수 r 

int empty() {
	return (top == -1);		//empty() 함수는 top == -1 을 리턴함
}

int full() {					// full() 함수는 top == MAX -1 을 리턴함
	return (top == (MAX - 1));	
}

void push(int ele) {
	if (full()) {
		printf("스택 초과");	 
		return;					//스택을 초과하면 리턴값이 아무것도 없음.
	}
	else
		stack[++top] = ele;
}

int pop() {
	if (empty()) {
		return 0;					//스택이 공백이면 나중에 더했을때 지장이 없기 위해 리턴값을 0으로 리턴
	}
	else
		return stack[top--];
}

int size() {
	return (top + 1);
}

void main() {
	printf("입력 :");
	int a;
	scanf_s("%d", &a);				//입력한 만큼 숫자를 작성 가능	

	for (int i = 0; i < a; i++) {
		int x;
		scanf_s("%d", &x);
		if (x == 0) {				// 입력한 숫자가 0일때, 문제에서 제시 된 것 처럼,
			pop();					// 실수로 부른 값이라고 보고 맨위의 값을 빼준다.
		}
		else {
			push(x);
		}
	}
	printf("\n");
	for (int i = size(); i > -1; i--) {
		r += pop();					// 최종적으로 스택에 있는 값을 모두 더하기 위해 값을 빼서 전부 더해준다.
	}
	printf("%d", r);
}	