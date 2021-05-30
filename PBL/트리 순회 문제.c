#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}Node;

Node* search(Node* root, element key) {	//��Ұ� ���� ���� �̱⿡
	if (root == NULL)
		return NULL;

	if (root != NULL) {	//Ʈ���� ������� �ʴٸ�,
		if (root->data == key) {	//��Ʈ�� ���� �°� ã������ �� ���(��Ʈ)�� ����
			return root;
		}
		else {	//ã�� ���Ͽ��ٸ�,
			Node* p = search(root->left, key);	//�������� ��� ������ ã��,
			if (p != NULL) {		//���� �� ��� p ���� ���´ٸ�,
				return p;		// �� p���� ����
			}
			return search(root->right, key);	//�ȳ��´ٸ�, ���������� ����.(�̰͸��� ���ٸ� ���� NULL�� ���� �����Ϳ��� �ɸ� ����.)
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
	root->data = A;	// ���(��Ʈ)�� A �� �켱������ �ְ�,
	if (B != '.') {
		root->left = new_node(B);	//����,
	}
	if (C != '.') {
		root->right = new_node(C);	//�����ʿ� ���� ���� �ִ´�.
	}
}

void inorder(Node* root) { //Ʈ���� ���� ��ȸ����̴�. ���� �ڽĳ�带 ���� �湮�ϰ� ��Ʈ�� �湮�ϰ� ���������� ������ �ڽĳ�带 �湮�Ѵ�
	if (root) {
		inorder(root->left);
		printf("[%c] ", root->data);
		inorder(root->right);
	}
}

void preoder(Node* root) { //Ʈ���� ���� ��ȸ����̴�. ��Ʈ�� ���� �湮�ϰ� �����ڽĳ�带 �湮�ϰ� ���������� ������ �ڽĳ�带 �湮�Ѵ�.
	if (root) {
		printf("[%c] ", root->data);
		preoder(root->left);
		preoder(root->right);
	}
}

void postorder(Node* root) {//Ʈ���� ���� ��ȸ����̴�.  �����ڽ��� ���� �湮�ϰ� ������ �ڽ��� �湮�� �� ���������� ��Ʈ�� �湮�Ѵ�
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%c] ", root->data);
	}
}

int main() {
	Node* root = new_node(NULL);	//�� Ʈ��
	Node* tmp;
	int n = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar(); //�Է� �� ����(\0)�� �ޱ� ����.
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
