#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}Node;

typedef struct HeadNode {// �����带 �����Ͽ�, ����Ʈ��ü�� ���ļ� ��带 �߰��ϴ°� �ƴ� ��峪 ������ ����Ͽ�, ÷���� ������
	int size;
	Node* head;
	Node* tail;
}ListType;   //����Ʈ Ÿ���� ��带 ���� ���� ��.

ListType* create() {	//������ �����Լ�. (�ϳ��� ����Ʈ�� �ٷ�)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	if (!plist) return NULL;
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;	//���� Ÿ���� ������ �����̱� ������ -> �ּҸ� �����ϸ� ��.
}

void insert_last(ListType* plist, int coef, int expon) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) exit(1);
	p->coef = coef;
	p->expon = expon;
	p->link = NULL;	// ����Ʈ�� ������ �κп� ��带 �߰��ϴ� ���̱� ������ �������� NULL �� ����Ų��.
	if (plist->tail == NULL) {
		plist->head = p;
		plist->tail = p;
	}
	else {
		plist->tail->link = p;	//���� ������ ��� �� p �� ����Ŵ (WHY: ���� �����ذ�.)
		plist->tail = p;	//�׳� tail �� �������� ����Ű�� �Ѱ�.
	}
	plist->size++;	//��带 �ϳ� �߰� �����Ƿ� ������ UP.
}

void poly_add(ListType* plist, ListType* plist1, ListType* plist2) {
	Node* a = plist1->head;	//���׽��� ���� ��带 ����.
	Node* b = plist2->head;	//���׽��� ���� ��鸦 ����(��, �� ��ü�� ��������)
	int sum;

	while (a && b) {	//a�� b ���� �ϳ��� �����ϸ�, ����
		if (a->expon == b->expon) {	// ���� �κ��� ���ٸ�, 
			sum = a->coef + b->coef;	// ����� ����
			if (sum != 0) {	//���� ����� 0 �� �ƴ϶��
				insert_last(plist, sum, a->expon);	//plist �� ����
			}
			a = a->link; b = b->link;	//a,b �Ѵ� ���� ���� �̵�
		}
		else if (a->expon > b->expon) {	// a�� ������ ũ�ٸ�
			insert_last(plist, a->coef, a->expon);	//a �� ������ plist �� ����
			a = a->link;
		}
		else {
			insert_last(plist, b->coef, b->expon);	// b�� ������ Ŭ���� ��������
			b = b->link;
		}
	}//while �ݺ����� ������ ���� a�� b�� ���� �����ִٸ� , �״�� plist �� ����.
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
