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

void poly_print(ListType* plist) {
	Node* p = plist->head;
	for (p; p != NULL; p = p->link) {
		printf(" %dx^%d +", p->coef, p->expon);
	}
	printf("\n");
}

void poly_eval(ListType* plist, double x) {
	Node* p = plist->head;
	double sum = 0;	//��ü ��� ����� ����.
	double xe = 1.0;	//���� �κ��� ����Ѱ��� ����.

	for (p; p != NULL; p = p->link) {
		for (int i = 0; i < p->expon; i++) {// �����κ�.
			xe = xe * x;	//expon ũ�⸸ŭ x�� ������
			//	printf("%d\n", xe);
		}
		sum = ((p->coef) * xe) + sum;	//������� ���� �ɶ� ���� sum �� ����ؼ� ����
		xe = 1.0;	//�ݺ����� �ѹ� ���� �ǰ� ������ �ٽ� xe �� 1�� �ʱ�ȭ( �ٽ� ���������� �ޱ� ���� )
	}
	printf("x= %.1f �� ��� ����: %.1f\n", x, sum);
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
