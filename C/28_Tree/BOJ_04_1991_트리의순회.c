#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;
node* tree[26];
void preorder(char data) {
	printf("%c", tree[data - 'A']->data);
	if (tree[data - 'A']->left != NULL) {
		preorder(tree[data - 'A']->left->data);
	}
	if (tree[data - 'A']->right != NULL) {
		preorder(tree[data - 'A']->right->data);
	}
}
void inorder(char data) {
	if (tree[data - 'A']->left != NULL) {
		inorder(tree[data - 'A']->left->data);
	}
	printf("%c", tree[data - 'A']->data);
	if (tree[data - 'A']->right != NULL) {
		inorder(tree[data - 'A']->right->data);
	}
}
void postorder(char data) {
	if (tree[data - 'A']->left != NULL) {
		postorder(tree[data - 'A']->left->data);
	}
	if (tree[data - 'A']->right != NULL) {
		postorder(tree[data - 'A']->right->data);
	}
	printf("%c", tree[data - 'A']->data);
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		tree[i] = (node*)malloc(sizeof(node));
		tree[i]->data = 'A' + i;
		tree[i]->left = NULL;
		tree[i]->right = NULL;
	}
	for (int i = 0; i < n; i++) {
		getchar();
		char root, left, right;
		scanf("%c %c %c", &root, &left, &right);
		if (left != '.') {
			tree[root - 'A']->left = tree[left - 'A'];
		}
		if (right != '.') {
			tree[root - 'A']->right = tree[right - 'A'];
		}
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");
}