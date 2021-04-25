#include <stdio.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value) //�Ҵ�� �޸��� ��Ī��  ���� �����Ƿ� �ּҸ� �޴´�. 
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //�ʱ� list
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) //p�� �����Ϳ� value�� �ְ� p�� link�� pre�� link�� �ٲ۴�. pre�� link�� p�� �ּҸ� ����Ų��. 
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode* head)  //removed �����ϰ� removed�� head�� ���� �� removed�� ��ũ�� head�� ����Ų�� ����� removed�� �޸𸮸� ��ȯ�Ѵ�.
{
    ListNode* removed;
    if (head == NULL)return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre)  //removed�� �����ϰ� �̴� pre�� link�� ����Ų��. �� ������� �ϴ� list�� �ּҰ��̴�. removed�� link�� ����� list�� �ּҸ� ����Ų��.    removed�� �޸𸮸� ��ȯ
{
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
void print_list(ListNode* head) //head���� null�� �ƴ� ������ link�� ���� ������ ���� ����Ѵ�.
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main(void) {

    ListNode* head = NULL;
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}