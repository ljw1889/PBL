#define _CRT_SECUERE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef int element;

typedef struct {
	element data[MAX];
	int f;
	int r;
}Q;	//ť Ÿ�� �����

void init(Q* q, int a) {	//ť �ʱ�ȭ
	q->f = -1;
	q->r = -1;
}

int is_full(Q* q) {	//����á����
	return ((q->f) == MAX - 1);
}

int is_empty(Q* q) {	//�������
	return ((q->f) == (q->r));
}

void Push(Q* q, element item) { //�����Լ�
	if (is_full(q)) {
		printf("error");
		return;
	}
	else {
		q->f++;
		q->data[(q->f)] = item;
	}
}


element Pop(Q* q) {	//��Ҹ� ����
	if (is_empty(q)) {
		exit(1);
	}
	else {
		q->r++;
		return ((q->data[(q->r)]));
	}
}

void Josephus(int l, int n) {	//�似Ǫ�� ������ ������ִ� �Լ�.
	Q q;
	int a = 0;
	init(&q, l);
	//ť�� �����
	for (int i = 1; i < l + 1; i++) {//�Ű������� ���� l ��ŭ ť�� ��Ҹ� ����
		Push(&q, i);
	}

	while (!is_empty(&q)) {
		for (int i = 0; i < n; i++) {	//�Ű������� ���� n ��ŭ �ݺ�
			element e = Pop(&q);	//�� ť���� n���� ���� �ٽ� �װ�, n ��°�� ���� ����

			if (i == n - 1) {	//���� �ּ����� ������ if �� �ɾ��� (ť���� n��° ���� �����°�)
				printf("%d ", e);
				continue;
			}
			Push(&q, e);
		}
	}
}

void main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	Josephus(a, b);
}