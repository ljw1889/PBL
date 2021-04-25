#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    int cmd;

    int stack[10000];
    int i;
    int top;
    char input[5];
    scanf("%d", &N); //N회 명령어 시행
    top = 0;

    for (i = 0; i < N; i++) {

        scanf("%s", &input);

        if (strcmp(input, "push") == 0) {
            scanf("%d", &cmd);              //입력한 cmd 값을 stack의 top에 넣는다.그 후 top의 값을 1 늘린다.

            stack[top] = cmd;
            top++;
        }

        else if (strcmp(input, "pop") == 0) {  //top이 가리키는 값을 하나 빼고 top의 값을 1 내린다.만약 top이 0이면 - 1을 출력한다.

            if (top == 0) {
                printf("%d\n", -1);
            }

            else {
                printf("%d\n", stack[top - 1]);
                top--;
            }
        }

        else if (strcmp(input, "size") == 0) { //top을 출력한다.
            printf("%d\n", top);
        }

        else if (strcmp(input, "top") == 0) { //top이 0일 경우 –1을 출력하고 아니면 stack[top-1]의 값을 출력한다.
            if (top <= 0) {
                printf("%d\n", -1);
            }
            else {
                printf("%d\n", stack[top - 1]);
            }
        }

        else if (strcmp(input, "empty") == 0) {  //top이 0이면 1을 출력하고 아니면 0을 출력한다.      
            if (top == 0) {
                printf("%d\n", 1);
            }
            else {
                printf("%d\n", 0);
            }
        }
    }
}