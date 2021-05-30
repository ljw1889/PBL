#include<stdio.h>
#include<stdlib.h>
int arr[100001], count = 0;	// �迭�� ���� ������ ���, count�� �迭�� ����� ������ ��Ʈ�� �ϱ� ����.

void push(int item) {
	arr[count] = item;
	count++;      //�������� ������, count �� 1 ����.
}

void pop() {
	int max = arr[0];  //�ִ밪�� �迭�� ó�� ������ ���� �ݺ����� ����Ͽ�, �ִ밪 Ž��
	for (int i = 0; i < count; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	printf("%d\n", max); //�ִ밪 ���

	for (int i = 0; i < count; i++) {
		if (max == arr[i]) {  //�迭���� �ִ밪�� ���� �ε����� �ִٸ�, �� �迭�� ��Ҵ� 0 ���� �Ҵ�.
			arr[i] = 0;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a;
	while (n--) {
		scanf("%d", &a);
		if (a == 0) { // �Է� ���� 0 �̶�� pop
			if (count == 0) {
				printf("0\n"); //�迭�� ����� ��, 0���� ��µǰ� ��.
				continue;
			}
			pop();
		}
		if (a != 0) { // �Է� ���� 0 �� �ƴ� �ڿ��� ��� push
			push(a);
		}
	}
	return 0;
}