#include <stdio.h>
#include <string.h>
int queue[2000001];
int front = 0;
int rear = -1;
void clean(char arr[]);  //�ʱ�ȭ��
void push(int x);    // push,pop,size,empty �Լ��� ����
void pop(void);
void size(void);
void empty(void);
int main(void) {
    int n, i, x;
    char command[6];
    scanf("%d", &n); //������ Ƚ�� n ����
    for (i = 0; i < n; i++) {          //����� �Է� ������ ��ɾ �Է¹����� �׿� �´� �Լ��� ����ȴ�. ex)pop �Է� �� pop() ����
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &x);
            push(x);
        }
        else if (!strcmp(command, "pop")) pop();
        else if (!strcmp(command, "size")) size();
        else if (!strcmp(command, "empty")) empty();
        else if (!strcmp(command, "front"))   //front�� �� ���� �� ��� rear �� �� �� �� ��� ť�� �������  -1 ���
        {
            if (rear - front + 1 == 0) printf("%d\n", -1);
            else printf("%d\n", queue[front]);
        }
        else if (!strcmp(command, "back")) {
            if (rear - front + 1 == 0) printf("%d\n", -1);
            else printf("%d\n", queue[rear]);
        }
        clean(command);
    }
    return 0;
}
void clean(char arr[]) { int i; for (i = 0; i < 6; i++) arr[i] = '\0'; } //�ʱ�ȭ�� �迭 
void push(int x) { queue[++rear] = x; } //������ �Լ����� � ������ �ϴ� �� ����,push�� �Է��� x�� ���� ť�� �ִ´�,pop�� ť �� ���� ���� ���� ���� �� -1���,  size �� rear-front+1�� ���� ���
void pop(void) { if (rear - front + 1 == 0) printf("%d\n", -1); else printf("%d\n", queue[front++]); }
void size(void) { printf("%d\n", rear - front + 1); }
void empty(void) { if (rear - front + 1 != 0) printf("%d\n", 0); else printf("%d\n", 1); }
