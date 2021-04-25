#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;
void init_stack(StackType* s) {
    s->top = -1;
}
int is_empty(StackType* s) {
    return(s->top == -1);
}
int is_full(StackType* s) {
    return(s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) {
    if (is_full(s)) {
        printf(stderr, "스택에러\n");
        return;

    }
    else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택공백에러\n");
        exit(1);
    }
    else return   s->data[(s->top)--];
}

int check_matching(const char* in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);//n= 문자열의 길이
    init_stack(&s); //스택 초기화

    for (i = 0; i < n; i++) {
        ch = in[i];   //다음 문자
        switch (ch) {
        case '(': case'[': case'{':  //왼쪽 괄호를 입력받으면 stack에 넣는다
            push(&s, ch);
            break;
        case')': case']': case'}':  //stack이 비었으면 return 오른쪽 괄호들을 만나면 pop실행
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
                {
                    return 0;
                }
                break;

            }
        }
    }
    if (!is_empty(&s)) return 0; //스택에 괄호가 남아있으면 오류
    return 1;
}

int main(void) {
    char* p = "A[(i+1)]=0;";  //검사하고자 하는 식
    if (check_matching(p) == 1)
        printf("%s 괄호검사 성공\n", p);

    else
        printf("%s 괄호검사 실패\n", p);
    return 0;


}