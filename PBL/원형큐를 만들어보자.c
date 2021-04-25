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

int is_empty(QueueType* q) {  //front���� rear�� ���� ���� ��� ����
    return(q->front == q->rear);
}

int is_full(QueueType* q) {  //front�� ���� rear���� 1 ���� �� ������� �������� ���� ���� ���� �� ��ȭ
    return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q) { //ť�� ����� ������ ����Ѵ�.
    printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;  //i�� q�� front ���� �� i�� rear�� ���� �� �� ����  i index�� �����͸� ����Ѵ�
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d|", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) //ť�� ��ȭ���¸� ����, q�� rear���� 1 ���ϰ� ť ������ ��ŭ ���� �������� index�� �ִ´� �� index�� data�� �Է��� ���� item�̴�.
{
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) { //ť�� ������� ����, q�� front���� 1���� �� �� ť ����� ���� �������� indext���� �ٲ� q�� index �����͸� ��ȯ
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void)
{
    QueueType queue;
    int element;
    init_queue(&queue);
    printf("--������ �߰� �ܰ�--\n");
    while (!is_full(&queue)) {
        printf("������ �Է��Ͻÿ�");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("ť�� ��ȭ�����Դϴ�\n\n");
    printf("-�����ͻ����ܰ�--\n");
    while (!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("������ �Լ�: %d\n", element);
        queue_print(&queue);
    }
    printf("ť�� ��������Դϴ�\n");
    return 0;
}