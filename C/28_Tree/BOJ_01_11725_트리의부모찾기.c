#include <stdio.h>
#include <stdlib.h>
int n, parent[100001], visited[100001];
typedef struct node {
	int data;
	struct node* next;
} node;
void add(node* target, int data) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
	now->next = target->next;
	target->next = now;
	return;
}
node* list[100001];
void dfs(int idx) {
	if (visited[idx]) {
		return;
	}
	visited[idx] = 1;
	node* curr = list[idx]->next;
	while (curr != NULL) {
		if (!visited[curr->data]) {
			parent[curr->data] = idx;
			dfs(curr->data);
		}
		curr = curr->next;
	}
}
main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		list[i] = (node*)malloc(sizeof(node));
		list[i]->next = NULL;
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add(list[x], y);
		add(list[y], x);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
}