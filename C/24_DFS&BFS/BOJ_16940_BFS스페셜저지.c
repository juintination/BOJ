#include <stdio.h>
#include <stdlib.h>
int n, cnt = 0, arr[100001], sorted[100001], visited[100001], order[100001];
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
int queue[100001], f = 0, r = 0;
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
void bfs(int idx) {
	push(idx);
	while (!empty()) {
		int tmp = pop();
		if (tmp != arr[cnt++]) {
			printf("0");
			exit(0);
		}
		visited[tmp] = 1;
		node* curr = list[tmp]->next;
		while (curr != NULL) {
			if (!visited[curr->data]) {
				push(curr->data);
				visited[curr->data] = 1;
			}
			curr = curr->next;
		}
	}

}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a, o2 = *(int*)b;
	return order[o1] - order[o2];
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
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		order[arr[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		node* curr = list[i]->next;
		while (curr != NULL) {
			sorted[tmp++] = curr->data;
			curr = curr->next;
		}
		list[i]->next = NULL;
		qsort(sorted, tmp, sizeof(int), compare);
		while (tmp > 0) {
			add(list[i], sorted[--tmp]);
		}
	}
	bfs(1);
	printf("1");
}