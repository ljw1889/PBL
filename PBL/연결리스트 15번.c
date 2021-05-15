#include<stdio.h>
#include<stdlib.h>
#include<string.h>	

typedef int element; //��� Ÿ�� ����

typedef struct Node { //��� Ÿ��
	element data;
	struct Node* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) { //ù�κп� ��� ����
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode)); // ��� ������ ���� �Ҵ�. ( �� �� �� �� �� �� )
	if (!p) { return NULL; }
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf(" %d ->", p->data);
	}
	printf("NULL\n");
}

void minAnMax(ListNode* head) {
	ListNode* p = head;
	int max = head->data; //ù���� ��Ҹ� max
	int min = head->data; //ù��° ��Ҹ� �����ϰ� min
	for (p; p != NULL; p = p->link) {
		if (max < p->data) { //����Ʈ�� ���� �� ���� �� �ϸ鼭 max ���� ũ�ٸ� �� ���� max�� 
			max = p->data;
		}
		if (min > p->data) { //����Ʈ�� ���� �� ���� �� �ϸ鼭 min ���� �۴ٸ� �� ���� min�� 
			min = p->data;
		}
	}
	printf("\n%d %d", max, min);
}




void main() {
	ListNode* head = NULL; //���ο� head �����͸� ����.
	int random = 0;
	for (int i = 0; i < 10; i++) {
		random = rand() % 100 + 1;	//1~100 ������ ������ �����ϰ�
		head = insert_first(head, random);	//������ ����Ʈ�� ����
	}
	print_list(head);
	minAnMax(head);
}