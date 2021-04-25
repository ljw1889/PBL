#include<stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5   
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {  //front값과 rear의 값이 같을 경우 공백
    return(q->front == q->rear);
}

int is_full(QueueType* q) {  //front의 값과 rear에서 1 더한 뒤 사이즈로 나누었을 때의 값이 같을 때 포화
    return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q) { //큐에 저장된 값들을 출력한다.
    printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;  //i가 q의 front 값일 때 i가 rear의 값이 될 때 까지  i index의 데이터를 출력한다
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d|", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) //큐가 포화상태면 오류, q의 rear값에 1 더하고 큐 사이즈 만큼 나눈 나머지를 index에 넣는다 그 index에 data는 입력한 정수 item이다.
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) { //큐가 비었으면 오류, q의 front값에 1더한 값 의 큐 사이즈를 나눈 나머지를 indext설정 바뀐 q의 index 데이터를 반환
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void)
{
    QueueType queue;
    int element;
    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue)) {
        printf("정수를 입력하시오");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다\n\n");
    printf("-데이터삭제단계--\n");
    while (!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("꺼내진 함수: %d\n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다\n");
    return 0;
}