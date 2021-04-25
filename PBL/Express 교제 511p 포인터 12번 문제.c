#include<stdio.h>

void get_int(int* px, int* py){    //포인터로 매개변수를 받는다 즉, 주소를 참조 한다.
	int r = *px + *py;
	printf("%d", r);
}

int main(){
	int a, b;
	int* A, B;

	A = &a;
	B = &b;

	scanf_s("%d %d", A, B);  //scanf_s("%d %d",&a,&b); 와 동일.

	get_int(A, B);				// 주소를 참조하여서 더하는 함수를 만듦.	
}