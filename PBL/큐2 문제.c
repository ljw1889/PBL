#include <stdio.h>
#include <string.h>
int queue[2000001];
int front = 0;
int rear = -1;
void clean(char arr[]);  //초기화용
void push(int x);    // push,pop,size,empty 함수를 선언
void pop(void);
void size(void);
void empty(void);
int main(void) {
    int n, i, x;
    char command[6];
    scanf("%d", &n); //시행할 횟수 n 지정
    for (i = 0; i < n; i++) {          //명령을 입력 각각의 명령어를 입력받으면 그에 맞는 함수가 실행된다. ex)pop 입력 시 pop() 실행
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &x);
            push(x);
        }
        else if (!strcmp(command, "pop")) pop();
        else if (!strcmp(command, "size")) size();
        else if (!strcmp(command, "empty")) empty();
        else if (!strcmp(command, "front"))   //front는 맨 앞의 수 출력 rear 는 맨 뒤 수 출력 큐가 비었으면  -1 출력
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
void clean(char arr[]) { int i; for (i = 0; i < 6; i++) arr[i] = '\0'; } //초기화용 배열 
void push(int x) { queue[++rear] = x; } //각각의 함수들이 어떤 역할을 하는 지 정의,push는 입력한 x의 값을 큐에 넣는다,pop은 큐 맨 앞의 값을 빼고 없을 시 -1출력,  size 는 rear-front+1의 값을 출력
void pop(void) { if (rear - front + 1 == 0) printf("%d\n", -1); else printf("%d\n", queue[front++]); }
void size(void) { printf("%d\n", rear - front + 1); }
void empty(void) { if (rear - front + 1 != 0) printf("%d\n", 0); else printf("%d\n", 1); }
