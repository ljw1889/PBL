#include<stdio.h>
#include<stdlib.h>
#define MAX 100	

typedef struct {
	int* data;				//data 는 포인터로 정의한다 (나중에 "스택을 초기화" 할때, 동적 할당으로 크기를 정해줄 거임.
	int capac;	
	int top;
}Stack;						//Stack타입을 정의함.           

void init(Stack* s) {
	s->top = -1;
	s->capac = 1;			//Stack생성 시에 용량을 1로 정의함 (나중에 스택을 더 추가할 때에, 용량을 1씩 늘릴 것임.)
	s->data = (int*)malloc(s->capac * sizeof(int));		// data크기를 정할때, capac을 곱해서 들어가는 개수에 맞는 크기를 곱해서 정해줌.
}

int full(Stack* s) {
	return (s->top == ((s->capac) - 1));  
}

int empty(Stack* s) {
	return (s->top == -1);
}

void push(Stack* s, int item) {
	if (full(s)) {
		s->capac += 1;					//가득 찼다면, 용량을 +1 해주고,
		s->data = (int*)realloc((s->data), (s->capac) * sizeof(int)); // 해준 용량만큼 realloc 함수를 써서 할당된 메모리 공간을 늘려준다. (tip. reallc(이미 할당된 포인터,바꾸고 싶은 공간의 크기))
	}
	s->data[++(s->top)] = item;  
}

int pop(Stack* s) {
	if (empty(s)) {
		printf("스택공백\n");
		exit(1);
	}
	else
		return (s->data[(s->top)--]);
}

int size(Stack* s) {
	return (s->capac);			//스택의 크기를 리턴 해준다.
}
void main() {
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));	//동적으로 스택을 생성하였다.

	init(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	printf("%d\n\n", size(s));

	for (int i = 0; i < size(s); i++) {		//스택의 크기만큼 반복하여 스택에 있는 모든 요소들을 빼주었다.
		printf("%d\n", pop(s));
	}
	free(s);			//스택을 동적으로 할당 했기에, 메모리공간을 마지막에 풀어주었다.
}