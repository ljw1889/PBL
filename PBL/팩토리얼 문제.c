#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fact(int n) {
    if (n > 1)  //n이 1보다 크면 n과 n이전항의 곱을 return한다.
        return n * fact(n - 1);
    else return 1; //n이 1이하이면 1을 return한다. ex)0!=1,1!=1
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", fact(x));
}