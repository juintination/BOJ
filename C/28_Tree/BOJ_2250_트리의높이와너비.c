#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, cnt = 1, dpth = 1, arr[10001], visited[10001], max[10001], min[10001];
typedef struct node {
	int data, parent;
	struct node* left;
	struct node* right;
} node;
node* tree[10001];
void inorder(int data, int level) {
	if (tree[data]->left != NULL) {
		inorder(tree[data]->left->data, level + 1);
	}
	max[level] = math_max(max[level], cnt);
	min[level] = math_min(min[level], cnt);
	arr[cnt++] = level;
	if (tree[data]->right != NULL) {
		inorder(tree[data]->right->data, level + 1);
	}
	dpth = math_max(dpth, level);
}
main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		tree[i] = (node*)malloc(sizeof(node));
		tree[i]->data = i;
		tree[i]->parent = -1;
		tree[i]->left = NULL;
		tree[i]->right = NULL;
		max[i] = 0;
		min[i] = n;
	}
	for (int i = 0; i < n; i++) {
		int data, left, right;
		scanf("%d %d %d", &data, &left, &right);
		if (left != -1) {
			tree[left]->parent = data;
			tree[data]->left = tree[left];
		}
		if (right != -1) {
			tree[right]->parent = data;
			tree[data]->right = tree[right];
		}
	}
	int root = 1;
	for (int i = 1; i <= n; i++) {
		if (tree[i]->parent == -1) {
			root = i;
			break;
		}
	}
	inorder(root, 1);
	int width = 0, level = 1;
	for (int i = 2; i <= dpth; i++) {
		int tmp = max[i] - min[i];
		if (tmp > width) {
			width = tmp;
			level = i;
		}
	}
	printf("%d %d", level, width + 1);
}