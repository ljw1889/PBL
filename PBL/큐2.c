#include<stdio.h>
#include<stdlib.h>
#define MAX 5	

typedef int element;						//data Ÿ���� ���߿� �ٲٰ� �ɶ� �ϰ������� �ٲ� �� �ֵ��� element �� ǥ����.

typedef struct {
	int front;							// ����, ������Ʈ�� ����(pop) ����, front�� ����.
	int rear;							// ����(������), ������Ʈ�� �߰�(push) �� ����, rear �� ����.
	element data[MAX];
}Queue;

void init(Queue* q) {
	q->front = -1;
	q->rear = -1;							//�հ� �ڸ� �����ϰ� ���缭 �ʱ�ȭ
}

int full(Queue* q) {
	if (q->rear == MAX - 1) {				//'������ �ִ�ũ�⿡ ����'�ߴٸ�, ť���� ������ ���°�
		return 1;
	}
	else
		return 0;
}

int empty(Queue* q) {
	if (q->front == q->rear) {			//�հ� ������, ������ ũ�⸦ �����ٸ�, ť�� ����ִ°�
		return 1;
	}
	else {
		return 0;
	}
}

void push(Queue* q, element item) {
	if (full(q)) {									//if (full()) �̶�� �Ŵ� ������ų rear �� ���ٴ� �Ҹ�.
		printf("ť ��ȭ");
		exit(1);
	}
	else {
		q->data[++(q->rear)] = item;				//�ڿ��� ���� �������� ���� �ڷᱸ����, "������ �������� item �� �ִ´�."
	}
}

element pop(Queue* q) {
	if (empty(q)) {
		printf("ť ����");
		exit(1);
	}
	element i = q->data[++(q->front)];			//������ �� �� �տ� �ִ� ��� ���� �����⿡ ó���̶�� -1 �� �Ǿ��ִ� front �� ���� ��Ű�°�ó��
	return i;										//front�� �������Ѽ� ���� ��Ҹ� �����ѵڿ� ������.
}

int size(Queue* q) {
	return ((q->rear + 1) - (q->front + 1));    //pop() �Լ��� �ѹ��� �Ⱦ���������, front �� -1 �̹Ƿ� �׿� ��ü������ +1 �� ���ߴ�.
}

int front(Queue* q) {
	return (q->data[(q->front + 1)]);				//�� ���� ��Ҹ� �ľ��ϱ� ���� front �� 1�� ���� ���� ��Ҹ� Ȯ���ߴ�, front�� ��� 
}

int back(Queue* q) {
	return (q->data[(q->rear)]);					//�� ���� ��Ҹ� �ľ��ϱ����� rear ��ġ�� ���� ���� �Ͽ���.
}


void main() {
	Queue q;
	init(&q);								// ť ���� �� �ʱ�ȭ

	push(&q, 1);
	push(&q, 2);
	push(&q, 3);								// ť ��� ����
	printf("������ : %d\n", size(&q));
	printf("����Ʈ : %d\n", front(&q));
	printf("back : %d\n", back(&q));

	printf("%d\n", pop(&q));
	printf("������ : %d\n", size(&q));
	printf("����Ʈ : %d\n", front(&q));
	printf("back : %d\n", back(&q));
	printf("%d\n", pop(&q));
	printf("%d\n", pop(&q));
}