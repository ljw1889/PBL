
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {	//����ü�� element Ÿ���� ����
	char name[100];
	int age;
	double heigh;
}element;

typedef struct ListNode {
	element data;	//data ���� �̸��� ���̿� Ű�� ���� ��.
	struct ListNode* link;
}Node;

Node* insert_head(Node* head, element item) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));

	p->data = item;		//�׳� �Ҵ縸 �ϸ� ��.
	p->link = head;
	head = p;

	return head;
}

void print_list(Node* head) {
	for (Node* p = head; p != NULL; p = p->link) {	//��� p �� ����� head �ּҸ� �Ҵ��ϰ� p�� �ּҰ� NULL�� �ɶ� ����, �� ����Ʈ�� ������ ���� �ݺ����� ����
		printf("Name: %s Age: %d Heigh: %.1f -> ", p->data.name, p->data.age, p->data.heigh);
	}
	printf("NULL \n");
}

void main() {
	Node* head = NULL;

	element data[4];

	strcpy(data[0].name, "choi");
	data[0].age = 30;
	data[0].heigh = 1.3;
	strcpy(data[1].name, "lee");
	data[1].age = 48;
	data[1].heigh = 1.4;
	strcpy(data[2].name, "park");
	data[2].age = 27;
	data[2].heigh = 1.2;
	strcpy(data[3].name, "kim");
	data[3].age = 34;
	data[3].heigh = 1.7;
	//������ ���� ��.
	for (int i = 0; i < 4; i++) {
		head = insert_head(head, data[i]);	//�ݺ����� ����Ͽ� �����͸� �־� ��
	}
	print_list(head);
}