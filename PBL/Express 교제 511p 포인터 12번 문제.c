#include<stdio.h>

void get_int(int* px, int* py){    //�����ͷ� �Ű������� �޴´� ��, �ּҸ� ���� �Ѵ�.
	int r = *px + *py;
	printf("%d", r);
}

int main(){
	int a, b;
	int* A, B;

	A = &a;
	B = &b;

	scanf_s("%d %d", A, B);  //scanf_s("%d %d",&a,&b); �� ����.

	get_int(A, B);				// �ּҸ� �����Ͽ��� ���ϴ� �Լ��� ����.	
}