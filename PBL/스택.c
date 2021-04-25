#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int element;
element stack[MAXSIZE];   // 100 ũ�� ��ŭ�� ������ �迭�� ������.
int top = -1;

int empty() {
	return (top == -1);
}

int full() {
	return (top == (MAXSIZE - 1));
}

void push(element item) {
	if (full()) {
		printf("���� �ʰ�\n");
		return;
	}
	else stack[++top] = item;   // ������ �ʰ� �Ǿ��� �ʴٸ�, top �� ���� ���� �� ��ҿ� item �� �߰���.
}

int pop() {
	if (empty()) {
		printf("���� ����\n");
		exit(1);
	}
	else {
		return stack[top--];  // ������ ������� �ʴٸ�, ���� ���� ���� ��Ҹ� �����ϰ� top �� -1.
	}
}

int peek() {
	if (empty()) {
		printf("���� ����\n");
		return 0;
	}
	else {
		return stack[top];   // ���� ���� ��Ҹ� ����.
	}
}

int size() {
	if (empty()) {
		printf("���� ����\n");
		return 0;
	}
	return (top + 1);   // ������ ����� ������.
}

int main(void) {
	push(1);
	push(2);
	push(3);
	printf("������ : %d\n", size());
	printf("%d\n", peek());
	printf("%d\n", pop());
	printf("������ : %d\n", size());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}