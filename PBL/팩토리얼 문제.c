#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fact(int n) {
    if (n > 1)  //n�� 1���� ũ�� n�� n�������� ���� return�Ѵ�.
        return n * fact(n - 1);
    else return 1; //n�� 1�����̸� 1�� return�Ѵ�. ex)0!=1,1!=1
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", fact(x));
}