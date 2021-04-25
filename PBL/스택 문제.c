#include <stdio.h>
#define MAX 100000

int stack[MAX];
int top = -1;

void push(int data) {      //top에 data를 넣고 top의 값을 1증가
    if (top >= MAX - 1)
        return;
    stack[++top] = data;
}

void pop() {           // top의 값에 0을 넣는다 즉, 앞의 top값을 지운다는 의미와같다.이후에 top의 값을 1 줄인다.

    if (top < 0)
        return;
    stack[top--] = 0;
}

int main(void) {
    int k;
    int data, sum = 0;
    scanf("%d", &k); //k회 시행
    while (k--) {
        scanf("%d", &data); //값을 입력하고 0이 아니면 push 0이면 pop을 실행
        if (data == 0)
            pop();
        else
            push(data);
    }
    for (int i = 0; i <= top; i++) {  //stack 안 의 값을 더한다.
        sum += stack[i];
    }
    printf("%d\n", sum);
}