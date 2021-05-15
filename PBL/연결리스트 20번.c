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

void poly_add(ListType* plist, ListType* plist1, ListType* plist2) {
	Node* a = plist1->head;	//다항식의 시작 노드를 받음.
	Node* b = plist2->head;	//다항식의 시작 노들를 받음(즉, 식 전체를 받은것임)
	int sum;

	while (a && b) {	//a와 b 둘중 하나가 존재하면, 실행
		if (a->expon == b->expon) {	// 지수 부분이 같다면, 
			sum = a->coef + b->coef;	// 계수를 더함
			if (sum != 0) {	//더한 계수가 0 이 아니라면
				insert_last(plist, sum, a->expon);	//plist 에 삽입
			}
			a = a->link; b = b->link;	//a,b 둘다 다음 노드로 이동
		}
		else if (a->expon > b->expon) {	// a의 지수가 크다면
			insert_last(plist, a->coef, a->expon);	//a 의 정보만 plist 에 저장
			a = a->link;
		}
		else {
			insert_last(plist, b->coef, b->expon);	// b의 지수가 클때도 마찬가지
			b = b->link;
		}
	}//while 반복문이 끝나고 나서 a나 b에 식이 남아있다면 , 그대로 plist 로 복사.
	for (; a != NULL; a = a->link) {
		insert_last(plist, a->coef, a->expon);
	}
	for (; b != NULL; b = b->link) {
		insert_last(plist, b->coef, b->expon);
	}
}

void poly_print(ListType* plist) {
	Node* p = plist->head;
	for (p; p != NULL; p = p->link) {
		printf(" %dx^%d +", p->coef, p->expon);
	}
	printf("\n");
}

void main() {
	ListType* list, * list1, * list2;

	list = create();
	list1 = create();
	list2 = create();

	insert_last(list1, 3, 6);
	insert_last(list1, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -9, 0);
	poly_print(list1);

	insert_last(list2, -2, 6);
	insert_last(list2, -4, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);
	poly_print(list2);

	poly_add(list, list1, list2);
	poly_print(list);
}
