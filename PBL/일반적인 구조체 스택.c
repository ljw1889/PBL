#include<stdio.h>
#include<stdlib.h>
#define MAX 100	

typedef struct {
	int data[MAX];
	int top;
}StackType;         //구조체로 스택 타입을 생성함.

void init(StackType* s) {	// 매개변수로 구조체 포인터를 받음.
	s->top = -1;			// 스택을 초기화 하기 위해 top 에 -1 을 할당.
}

int full(StackType* s) {
	return (s->top == (MAX - 1));
}

int empty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, int item) {
	if (full(s)) {
		printf("스택 초과\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

int pop(StackType* s) {
	if (empty(s)) {
		printf("스택 공백\n");
		exit(1);
	}
	else {
		return (s->data[(s->top)--]);
	}
}

int peek(StackType* s) {
	if (empty(s)) {
		printf("스택 공백\n");
		exit(1);
	}
	else {
		return(s->data[(s->top)]);
	}
}

int size(StackType* s) {
	return (s->top + 1);
}
//스택의 끝

void main() {
	StackType s;		// 구조체로 생성한 스택을 선언.

	init(&s);			//스택 초기화.

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));		 //함수에 스택주소를 참조하여서 활용 할 수 있다.

}