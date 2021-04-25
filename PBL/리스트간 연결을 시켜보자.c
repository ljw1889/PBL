#include <stdio.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value) //할당된 메모리의 명칭이  따로 없으므로 주소를 받는다. 
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //초기 list
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) //p의 데이터에 value를 넣고 p의 link를 pre의 link로 바꾼다. pre의 link가 p의 주소를 가리킨다. 
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode* head)  //removed 생성하고 removed와 head가 같을 때 removed의 링크가 head를 가리킨다 사라진 removed의 메모리를 반환한다.
{
    ListNode* removed;
    if (head == NULL)return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre)  //removed를 생성하고 이는 pre의 link를 가리킨다. 즉 지우고자 하는 list의 주소값이다. removed의 link를 지우는 list의 주소를 가리킨다.    removed의 메모리를 반환
{
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
void print_list(ListNode* head) //head부터 null이 아닐 때까지 link를 통해 데이터 값을 출력한다.
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