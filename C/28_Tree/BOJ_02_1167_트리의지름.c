#include <stdio.h>
#include <stdlib.h>
int v, tmp, max = 0, visited[100001];
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
node* list[100001];
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
	scanf("%d", &v);
	for (int i = 1; i <= v; i++) {
		list[i] = (node*)malloc(sizeof(node));
		list[i]->next = NULL;
	}
	for (int i = 0; i < v; i++) {
		int n, data, cost;
		scanf("%d", &n);
		while (1) {
			scanf("%d", &data);
			if (data == -1) break;
			scanf("%d", &cost);
			add(list[n], data, cost);
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= v; i++) {
		visited[i] = 0;
	}
	dfs(tmp, 0);
	printf("%d", max);
}