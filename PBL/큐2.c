#include<stdio.h>
#include<stdlib.h>
#define MAX 5	

typedef int element;						//data 타입을 나중에 바꾸게 될때 일괄적으로 바꿀 수 있도록 element 로 표시함.

typedef struct {
	int front;							// 앞쪽, 엘리먼트가 빠질(pop) 수록, front가 증가.
	int rear;							// 꼬리(엉덩이), 엘리먼트가 추가(push) 될 수록, rear 가 증가.
	element data[MAX];
}Queue;

void init(Queue* q) {
	q->front = -1;
	q->rear = -1;							//앞과 뒤를 동일하게 맞춰서 초기화
}

int full(Queue* q) {
	if (q->rear == MAX - 1) {				//'꼬리가 최대크기에 도달'했다면, 큐에는 공간이 없는것
		return 1;
	}
	else
		return 0;
}

int empty(Queue* q) {
	if (q->front == q->rear) {			//앞과 꼬리가, 동일한 크기를 가진다면, 큐는 비어있는것
		return 1;
	}
	else {
		return 0;
	}
}

void push(Queue* q, element item) {
	if (full(q)) {									//if (full()) 이라는 거는 증가시킬 rear 가 없다는 소리.
		printf("큐 포화");
		exit(1);
	}
	else {
		q->data[++(q->rear)] = item;				//뒤에서 부터 정보들이 들어가는 자료구조라, "꼬리를 증가시켜 item 을 넣는다."
	}
}

element pop(Queue* q) {
	if (empty(q)) {
		printf("큐 공백");
		exit(1);
	}
	element i = q->data[++(q->front)];			//내보낼 때 는 앞에 있는 요소 먼저 나가기에 처음이라면 -1 로 되어있던 front 를 증가 시키는것처럼
	return i;										//front를 증가시켜서 앞의 요소를 지정한뒤에 내보냄.
}

int size(Queue* q) {
	return ((q->rear + 1) - (q->front + 1));    //pop() 함수가 한번도 안쓰였을때는, front 가 -1 이므로 항에 전체적으로 +1 을 더했다.
}

int front(Queue* q) {
	return (q->data[(q->front + 1)]);				//맨 앞의 요소를 파악하기 위해 front 에 1을 증가 시켜 요소를 확인했다, front는 요소 
}

int back(Queue* q) {
	return (q->data[(q->rear)]);					//맨 뒤의 요소를 파악하기위해 rear 위치의 값을 리턴 하였다.
}


void main() {
	Queue q;
	init(&q);								// 큐 생성 및 초기화

	push(&q, 1);
	push(&q, 2);
	push(&q, 3);								// 큐 요소 투입
	printf("사이즈 : %d\n", size(&q));
	printf("프론트 : %d\n", front(&q));
	printf("back : %d\n", back(&q));

	printf("%d\n", pop(&q));
	printf("사이즈 : %d\n", size(&q));
	printf("프론트 : %d\n", front(&q));
	printf("back : %d\n", back(&q));
	printf("%d\n", pop(&q));
	printf("%d\n", pop(&q));
}