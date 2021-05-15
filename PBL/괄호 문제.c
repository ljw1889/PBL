#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct {
	char str[100];
}element;

typedef struct stack {
	char data[MAX];
	int top;
}Stack;

void init(Stack* s) {
	s->top = -1;
}

int is_full(Stack* s) {
	if (s->top == MAX - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int is_empty(Stack* s) {
	if (s->top == -1) {
		return 1;	//비어있다는것.
	}
	else
		return 0;
}

void Push(Stack* s, char* item) {
	if (is_full(s) == 1) {
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
	}
}

char Pop(Stack* s) {
	if (is_empty == 1) {
		exit(1);
	}
	else {
		return ((s->data[(s->top--)]));
	}
}

int check(char* list) {
	Stack s;
	init(&s);
	char ch;
	char oc;

	int le = strlen(list);
	for (int i = 0; i < le; i++) {
		ch = list[i];
		switch (ch) {
		case'(':
			Push(&s, ch);	//괄호 만나면 쌓고
			break;
		case')':
			if (is_empty(&s)) {	// 조건 1. 쌓은게 있어야하는데 없으면, 0
				return 0;
			}
			else {
				oc = Pop(&s);
				if ((oc == '(' && ch != ')')) {	//조건 2. 맞는 짝이 아니면, 0
					return 0;
				}
				break;
			}
		default:
			break;
		}
	}
	if (is_empty(&s) != 1) {	//조건 3. 괄호가 남아있으면, 0 
		return 0;
	}
	return 1;
}

void main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char p[100];
		scanf("%s", p);
		if (check(p) == 1) {
			printf("성공\n");
		}
		else {
			printf("실패\n");
		}
	}
}