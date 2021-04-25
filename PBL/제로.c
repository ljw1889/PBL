#include <stdio.h>
#include <stdlib.h>
#define MAX 100	

int stack[MAX];				//�� ���α׷������� ������ �ϳ��� ���Ŷ� ���������� ����	
int top = -1;
int r = 0;                   //���� ������� ���� ���� r 

int empty() {
	return (top == -1);		//empty() �Լ��� top == -1 �� ������
}

int full() {					// full() �Լ��� top == MAX -1 �� ������
	return (top == (MAX - 1));	
}

void push(int ele) {
	if (full()) {
		printf("���� �ʰ�");	 
		return;					//������ �ʰ��ϸ� ���ϰ��� �ƹ��͵� ����.
	}
	else
		stack[++top] = ele;
}

int pop() {
	if (empty()) {
		return 0;					//������ �����̸� ���߿� �������� ������ ���� ���� ���ϰ��� 0���� ����
	}
	else
		return stack[top--];
}

int size() {
	return (top + 1);
}

void main() {
	printf("�Է� :");
	int a;
	scanf_s("%d", &a);				//�Է��� ��ŭ ���ڸ� �ۼ� ����	

	for (int i = 0; i < a; i++) {
		int x;
		scanf_s("%d", &x);
		if (x == 0) {				// �Է��� ���ڰ� 0�϶�, �������� ���� �� �� ó��,
			pop();					// �Ǽ��� �θ� ���̶�� ���� ������ ���� ���ش�.
		}
		else {
			push(x);
		}
	}
	printf("\n");
	for (int i = size(); i > -1; i--) {
		r += pop();					// ���������� ���ÿ� �ִ� ���� ��� ���ϱ� ���� ���� ���� ���� �����ش�.
	}
	printf("%d", r);
}	