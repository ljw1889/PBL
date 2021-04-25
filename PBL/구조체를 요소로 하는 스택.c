#include <stdio.h>
#include <stdlib.h>
#define MAX 100	

typedef struct {
	int num;
	char name[MAX];
	char add[MAX];
}element;           //���ÿ� �� ��Ҹ� element ����ü�� ������.

element stack[MAX];   // ������ �迭�� ������.
int top = -1;

int full() {
	return (top == MAX - 1);
}
int empty() {
	return (top == -1);
}
void push(element x) {
	if (full()) {
		printf("���� ��ȭ");
		return;
	}
	else
		stack[++top] = x;
}
element pop() {
	if (empty()) {
		printf("���� ����");
		exit(1);
	}
	else
		return stack[top--];
}
int size() {
	return (top + 1);
}

element peek() {
	if (empty()) {
		printf("���� ����");
		exit(1);
	}
	else
		return stack[top];
}

void main() {
	element x = { 123, "hong", "jinju" };	//element x �� �ϳ� �����

	push(x);									//element x �� ���ÿ� ���� �־���, �̶�, ������ ��� Ÿ���� ����ü �̱⿡ element�� �������� ���� ����. 

	element y = pop();							//element y �� ���ÿ� �־��� ��Ҹ� ���� �Ҵ���.

	printf("%d\n", y.num);
	printf("%s\n", y.name);
	printf("%s\n", y.add);					// ���������ڸ� �Ἥ �������� ��� �� �� ���ִ�.  �̷ν�, ����ü��ҵ� ���ÿ� �� ���� �߳����°Ÿ� �� �� �ִ�.
}

