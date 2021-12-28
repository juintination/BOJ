#include <stdio.h>
#include <stdlib.h>
int n, tmp = 1, max = 0, visited[10001];
typedef struct node {
	int data, cost;
	struct node* next;
} node;
void add(node* target, int data, int cost) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
	now->cost = cost;
	now->next = target->next;
	target->next = now;
	return;
}
node* list[10001];
void dfs(int idx, int len) {
	if (len > max) {
		max = len;
		tmp = idx;
	}
	visited[idx] = 1;
	node* curr = list[idx]->next;
	while (curr != NULL) {
		if (!visited[curr->data]) {
			dfs(curr->data, len + curr->cost);
			visited[curr->data] = 0;
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
		int idx, data, cost;
		scanf("%d %d %d", &idx, &data, &cost);
		add(list[idx], data, cost);
		add(list[data], idx, cost);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	dfs(tmp, 0);
	printf("%d", max);
}