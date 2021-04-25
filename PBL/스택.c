#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int element;
element stack[MAXSIZE];   // 100 크기 만큼의 스택을 배열로 생성함.
int top = -1;

int empty() {
	return (top == -1);
}

int full() {
	return (top == (MAXSIZE - 1));
}

void push(element item) {
	if (full()) {
		printf("스택 초과\n");
		return;
	}
	else stack[++top] = item;   // 스택이 초과 되었지 않다면, top 을 증가 시켜 그 요소에 item 을 추가함.
}

int pop() {
	if (empty()) {
		printf("스택 공백\n");
		exit(1);
	}
	else {
		return stack[top--];  // 스택이 비어있지 않다면, 스택 제일 위의 요소를 리턴하고 top 은 -1.
	}
}

int peek() {
	if (empty()) {
		printf("스택 공백\n");
		return 0;
	}
	else {
		return stack[top];   // 제일 위의 요소를 꺼냄.
	}
}

int size() {
	if (empty()) {
		printf("스택 공백\n");
		return 0;
	}
	return (top + 1);   // 스택의 사이즈를 리턴함.
}

int main(void) {
	push(1);
	push(2);
	push(3);
	printf("사이즈 : %d\n", size());
	printf("%d\n", peek());
	printf("%d\n", pop());
	printf("사이즈 : %d\n", size());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}