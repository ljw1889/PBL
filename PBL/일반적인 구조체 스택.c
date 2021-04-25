#include<stdio.h>
#include<stdlib.h>
#define MAX 100	

typedef struct {
	int data[MAX];
	int top;
}StackType;         //����ü�� ���� Ÿ���� ������.

void init(StackType* s) {	// �Ű������� ����ü �����͸� ����.
	s->top = -1;			// ������ �ʱ�ȭ �ϱ� ���� top �� -1 �� �Ҵ�.
}

int full(StackType* s) {
	return (s->top == (MAX - 1));
}

int empty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, int item) {
	if (full(s)) {
		printf("���� �ʰ�\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

int pop(StackType* s) {
	if (empty(s)) {
		printf("���� ����\n");
		exit(1);
	}
	else {
		return (s->data[(s->top)--]);
	}
}

int peek(StackType* s) {
	if (empty(s)) {
		printf("���� ����\n");
		exit(1);
	}
	else {
		return(s->data[(s->top)]);
	}
}

int size(StackType* s) {
	return (s->top + 1);
}
//������ ��

void main() {
	StackType s;		// ����ü�� ������ ������ ����.

	init(&s);			//���� �ʱ�ȭ.

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));		 //�Լ��� �����ּҸ� �����Ͽ��� Ȱ�� �� �� �ִ�.

}