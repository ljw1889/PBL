#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}Node;

typedef struct HeadNode {// 헤더노드를 생성하여, 리스트전체를 거쳐서 노드를 추가하는게 아닌 헤드나 테일을 사용하여, 첨삭이 쉬워짐
	int size;
	Node* head;
	Node* tail;
}ListType;   //리스트 타입이 노드를 바탕 으로 함.

ListType* create() {	//헤더노드 생성함수. (하나의 리스트를 다룸)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	if (!plist) return NULL;
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;	//리턴 타입이 포인터 형식이기 때문에 -> 주소를 리턴하면 됨.
}

void insert_last(ListType* plist, int coef, int expon) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) exit(1);
	p->coef = coef;
	p->expon = expon;
	p->link = NULL;	// 리스트의 마지막 부분에 노드를 추가하는 것이기 때문에 마지막은 NULL 을 가리킨다.
	if (plist->tail == NULL) {
		plist->head = p;
		plist->tail = p;
	}
	else {
		plist->tail->link = p;	//기존 마지막 노드 가 p 를 가리킴 (WHY: 연결 시켜준것.)
		plist->tail = p;	//그냥 tail 이 마지막을 가르키게 한것.
	}
	plist->size++;	//노드를 하나 추가 했으므로 사이즈 UP.
}

void poly_print(ListType* plist) {
	Node* p = plist->head;
	for (p; p != NULL; p = p->link) {
		printf(" %dx^%d +", p->coef, p->expon);
	}
	printf("\n");
}

void poly_eval(ListType* plist, double x) {
	Node* p = plist->head;
	double sum = 0;	//전체 계산 결과를 넣음.
	double xe = 1.0;	//제곱 부분을 계산한것을 넣음.

	for (p; p != NULL; p = p->link) {
		for (int i = 0; i < p->expon; i++) {// 제곱부분.
			xe = xe * x;	//expon 크기만큼 x를 곱해줌
			//	printf("%d\n", xe);
		}
		sum = ((p->coef) * xe) + sum;	//연결식이 진행 될때 동안 sum 을 계속해서 더함
		xe = 1.0;	//반복문이 한번 실행 되고 나서는 다시 xe 를 1로 초기화( 다시 제곱차수를 받기 위함 )
	}
	printf("x= %.1f 의 결과 값은: %.1f\n", x, sum);
}

void main() {
	ListType* list1;
	list1 = create();


	insert_last(list1, 1, 3);
	insert_last(list1, 2, 1);
	insert_last(list1, 6, 0);

	poly_print(list1);
	poly_eval(list1, 2.0);

}
