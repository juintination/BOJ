#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}
TreeNode* new_node(int data) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
TreeNode* insert_node(TreeNode* node, int data) {
	if (node == NULL) return new_node(data);
	if (data < node->data) {
		node->left = insert_node(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert_node(node->right, data);
	}
	return node;
}
main() {
	TreeNode* root = NULL;
	int value;
	while (scanf("%d", &value) != EOF) {
		root = insert_node(root, value);
	}
	postorder(root);
}