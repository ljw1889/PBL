#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}Node;

Node* search(Node* root, element key) {	//대소가 없는 문자 이기에
	if (root == NULL)
		return NULL;

	if (root != NULL) {	//트리가 비어있지 않다면,
		if (root->data == key) {	//루트의 값과 맞게 찾았으면 그 노드(루트)를 리턴
			return root;
		}
		else {	//찾지 못하였다면,
			Node* p = search(root->left, key);	//왼쪽으로 재귀 돌려서 찾고,
			if (p != NULL) {		//만약 그 노드 p 값이 나온다면,
				return p;		// 그 p값을 리턴
			}
			return search(root->right, key);	//안나온다면, 오른쪽으로 돌림.(이것마저 없다면 맨위 NULL로 리턴 잡은것에서 걸릴 것임.)
		}
	}
}

Node* new_node(element key) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = key;
	p->right = p->left = NULL;
	return p;
}

Node* insert_node(Node* root, element A, element B, element C) {
	root->data = A;	// 노드(루트)에 A 를 우선적으로 넣고,
	if (B != '.') {
		root->left = new_node(B);	//왼쪽,
	}
	if (C != '.') {
		root->right = new_node(C);	//오른쪽에 각각 값을 넣는다.
	}
}

void inorder(Node* root) { //트리의 중위 순회방식이다. 왼쪽 자식노드를 먼저 방문하고 루트를 방문하고 마지막으로 오른쪽 자식노드를 방문한다
	if (root) {
		inorder(root->left);
		printf("[%c] ", root->data);
		inorder(root->right);
	}
}

void preoder(Node* root) { //트리의 전위 순회방식이다. 루트를 먼저 방문하고 왼쪽자식노드를 방문하고 마지막으로 오른쪽 자식노드를 방문한다.
	if (root) {
		printf("[%c] ", root->data);
		preoder(root->left);
		preoder(root->right);
	}
}

void postorder(Node* root) {//트리의 후위 순회방식이다.  왼쪽자식을 먼저 방문하고 오른쪽 자식을 방문한 뒤 마지막으로 루트를 방문한다
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%c] ", root->data);
	}
}

int main() {
	Node* root = new_node(NULL);	//주 트리
	Node* tmp;
	int n = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar(); //입력 시 엔터(\0)를 받기 위함.
		tmp = search(root, a);
		if (tmp != NULL) {
			insert_node(tmp, a, b, c);
		}
		else
			insert_node(root, a, b, c);
	}
	preoder(root);
	printf("\n");

	inorder(root);
	printf("\n");

	postorder(root);
	printf("\n");
	return 0;
}
