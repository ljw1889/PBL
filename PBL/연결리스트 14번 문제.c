
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {	//구조체로 element 타입을 선언
	char name[100];
	int age;
	double heigh;
}element;

typedef struct ListNode {
	element data;	//data 에는 이름과 나이와 키가 저장 됨.
	struct ListNode* link;
}Node;

Node* insert_head(Node* head, element item) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));

	p->data = item;		//그냥 할당만 하면 됨.
	p->link = head;
	head = p;

	return head;
}

void print_list(Node* head) {
	for (Node* p = head; p != NULL; p = p->link) {	//노드 p 를 만들어 head 주소를 할당하고 p의 주소가 NULL이 될때 까지, 즉 리스트의 마지막 까지 반복문을 실행
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
	//값들을 저장 함.
	for (int i = 0; i < 4; i++) {
		head = insert_head(head, data[i]);	//반복문을 사용하여 데이터를 넣어 줌
	}
	print_list(head);
}