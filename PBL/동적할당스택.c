#include<stdio.h>
#include<stdlib.h>
#define MAX 100	

typedef struct {
	int* data;				//data �� �����ͷ� �����Ѵ� (���߿� "������ �ʱ�ȭ" �Ҷ�, ���� �Ҵ����� ũ�⸦ ������ ����.
	int capac;	
	int top;
}Stack;						//StackŸ���� ������.           

void init(Stack* s) {
	s->top = -1;
	s->capac = 1;			//Stack���� �ÿ� �뷮�� 1�� ������ (���߿� ������ �� �߰��� ����, �뷮�� 1�� �ø� ����.)
	s->data = (int*)malloc(s->capac * sizeof(int));		// dataũ�⸦ ���Ҷ�, capac�� ���ؼ� ���� ������ �´� ũ�⸦ ���ؼ� ������.
}

int full(Stack* s) {
	return (s->top == ((s->capac) - 1));  
}

int empty(Stack* s) {
	return (s->top == -1);
}

void push(Stack* s, int item) {
	if (full(s)) {
		s->capac += 1;					//���� á�ٸ�, �뷮�� +1 ���ְ�,
		s->data = (int*)realloc((s->data), (s->capac) * sizeof(int)); // ���� �뷮��ŭ realloc �Լ��� �Ἥ �Ҵ�� �޸� ������ �÷��ش�. (tip. reallc(�̹� �Ҵ�� ������,�ٲٰ� ���� ������ ũ��))
	}
	s->data[++(s->top)] = item;  
}

int pop(Stack* s) {
	if (empty(s)) {
		printf("���ð���\n");
		exit(1);
	}
	else
		return (s->data[(s->top)--]);
}

int size(Stack* s) {
	return (s->capac);			//������ ũ�⸦ ���� ���ش�.
}
void main() {
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));	//�������� ������ �����Ͽ���.

	init(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	printf("%d\n\n", size(s));

	for (int i = 0; i < size(s); i++) {		//������ ũ�⸸ŭ �ݺ��Ͽ� ���ÿ� �ִ� ��� ��ҵ��� ���־���.
		printf("%d\n", pop(s));
	}
	free(s);			//������ �������� �Ҵ� �߱⿡, �޸𸮰����� �������� Ǯ���־���.
}