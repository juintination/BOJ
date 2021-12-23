#include <stdio.h>
#include <stdlib.h>
int n, start, cnt[3001], visited[3001], cycled[3001];
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
node* list[3001];
int dfs(int idx, int parent) {
	visited[idx] = 1;
	node* curr = list[idx]->next;
	while (curr != NULL) {
		int e = curr->data;
		if (!visited[e]) {
			if (dfs(e, idx)) {
				cycled[e] = 1;
				return 1;
			}
		}
		else if (e != parent && e == start) {
			cycled[e] = 1;
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}
int queue[3001], f = 0, r = 0;
void push(int x) {
	queue[r++] = x;
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
int pop() {
	return queue[f++];
}
void bfs() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (cycled[i]) {
			visited[i] = 1;
			push(i);
		}
	}
	while (!empty()) {
		int tmp = pop();
		visited[tmp] = 1;
		node* curr = list[tmp]->next;
		while (curr != NULL) {
			int e = curr->data;
			if (!visited[e]) {
				push(e);
				visited[e] = 1;
				cnt[e] = cnt[tmp] + 1;
			}
			curr = curr->next;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		list[i] = (node*)malloc(sizeof(node));
		list[i]->next = NULL;
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add(list[x], y);
		add(list[y], x);
	}
	for (int i = 1; i <= n; i++) {
		start = i;
		if (dfs(i, 0)) break;
		else {
			for (int i = 1; i <= n; i++) {
				visited[i] = 0;
			}
		}
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}
}