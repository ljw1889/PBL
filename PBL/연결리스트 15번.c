#include<stdio.h>
#include<stdlib.h>
#include<string.h>	

typedef int element; //요소 타입 정의

typedef struct Node { //노드 타입
	element data;
	struct Node* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) { //첫부분에 노드 삽입
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode)); // 노드 포인터 동적 할당. ( 추 가 되 는 항 목 )
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
	int max = head->data; //첫번재 요소를 max
	int min = head->data; //첫번째 요소를 동일하게 min
	for (p; p != NULL; p = p->link) {
		if (max < p->data) { //리스트가 끝날 때 까지 비교 하면서 max 보다 크다면 그 값을 max에 
			max = p->data;
		}
		if (min > p->data) { //리스트가 끝날 때 까지 비교 하면서 min 보다 작다면 그 값을 min에 
			min = p->data;
		}
	}
	printf("\n%d %d", max, min);
}




void main() {
	ListNode* head = NULL; //새로운 head 포인터를 생성.
	int random = 0;
	for (int i = 0; i < 10; i++) {
		random = rand() % 100 + 1;	//1~100 까지의 난수를 생성하고
		head = insert_first(head, random);	//난수를 리스트에 저장
	}
	print_list(head);
	minAnMax(head);
}