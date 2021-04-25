#include <stdio.h>
#include <stdlib.h>
#define MAX 100	

typedef struct {
	int num;
	char name[MAX];
	char add[MAX];
}element;           //스택에 들어갈 요소를 element 구조체로 정의함.

element stack[MAX];   // 스택은 배열로 정의함.
int top = -1;

int full() {
	return (top == MAX - 1);
}
int empty() {
	return (top == -1);
}
void push(element x) {
	if (full()) {
		printf("스택 포화");
		return;
	}
	else
		stack[++top] = x;
}
element pop() {
	if (empty()) {
		printf("스택 공백");
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
		printf("스택 공백");
		exit(1);
	}
	else
		return stack[top];
}

void main() {
	element x = { 123, "hong", "jinju" };	//element x 를 하나 만들고

	push(x);									//element x 를 스택에 집어 넣어줌, 이때, 스택의 요소 타입이 구조체 이기에 element의 정보들이 전부 들어간다. 

	element y = pop();							//element y 에 스택에 넣었던 요소를 빼서 할당함.

	printf("%d\n", y.num);
	printf("%s\n", y.name);
	printf("%s\n", y.add);					// 참조연산자를 써서 정보들을 출력 할 수 가있다.  이로써, 구조체요소도 스택에 잘 들어가고 잘나오는거를 볼 수 있다.
}

