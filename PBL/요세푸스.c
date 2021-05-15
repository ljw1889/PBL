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
}Q;	//큐 타입 만들기

void init(Q* q, int a) {	//큐 초기화
	q->f = -1;
	q->r = -1;
}

int is_full(Q* q) {	//가득찼는지
	return ((q->f) == MAX - 1);
}

int is_empty(Q* q) {	//비었는지
	return ((q->f) == (q->r));
}

void Push(Q* q, element item) { //삽입함수
	if (is_full(q)) {
		printf("error");
		return;
	}
	else {
		q->f++;
		q->data[(q->f)] = item;
	}
}


element Pop(Q* q) {	//요소를 꺼냄
	if (is_empty(q)) {
		exit(1);
	}
	else {
		q->r++;
		return ((q->data[(q->r)]));
	}
}

void Josephus(int l, int n) {	//요세푸스 순열을 출력해주는 함수.
	Q q;
	int a = 0;
	init(&q, l);
	//큐를 만들고
	for (int i = 1; i < l + 1; i++) {//매개변수로 받은 l 만큼 큐에 요소를 투입
		Push(&q, i);
	}

	while (!is_empty(&q)) {
		for (int i = 0; i < n; i++) {	//매개변수로 받은 n 만큼 반복
			element e = Pop(&q);	//즉 큐에서 n전에 것은 다시 쌓고, n 번째의 수를 꺼냄

			if (i == n - 1) {	//위의 주석설명 과정을 if 로 걸어줌 (큐에서 n번째 수를 꺼내는것)
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