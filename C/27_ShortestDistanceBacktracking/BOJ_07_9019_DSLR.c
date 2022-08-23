#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int parent[10000], visited[10000];
typedef struct node {
	int data;
	struct node* next;
} node;
typedef struct Queue {
	node* front;
	node* rear;
	int count;
} Queue;
void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0;
}
void push(Queue* queue, int data) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
	now->next = NULL;
	if (queue->count == 0) {
		queue->front = now;
	}
	else {
		queue->rear->next = now;
	}
	queue->rear = now;
	queue->count++;
}
int pop(Queue* queue) {
	int re;
	node* now;
	if (queue->count == 0) {
		return -1;
	}
	now = queue->front;
	re = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs(int a, int b) {
	char str[10001];
	Queue queue;
	initQueue(&queue);
	push(&queue, a);
	visited[a] = 1;
	while (!empty(&queue)) {
		int p = pop(&queue);
		int d = (2 * p) % 10000;
		if (!visited[d]) {
			str[d] = 'D';
			parent[d] = p;
			if (d == b) break;
			visited[d] = 1;
			push(&queue, d);
		}
		int s = (p == 0) ? 9999 : p - 1;
		if (!visited[s]) {
			str[s] = 'S';
			parent[s] = p;
			if (s == b) break;
			visited[s] = 1;
			push(&queue, s);
		}
		int l = (p % 1000) * 10 + p / 1000;
		if (!visited[l]) {
			str[l] = 'L';
			parent[l] = p;
			if (l == b) break;
			visited[l] = 1;
			push(&queue, l);
		}
		int r = (p % 10) * 1000 + p / 10;
		if (!visited[r]) {
			str[r] = 'R';
			parent[r] = p;
			if (r == b) break;
			visited[r] = 1;
			push(&queue, r);
		}
	}
	char stack[10001];
	int idx = -1;
	while (b != a) {
		stack[++idx] = str[b];
		b = parent[b];
	}
	while (idx >= 0) {
		printf("%c", stack[idx--]);
	}
	printf("\n");
	node* curr = queue.front;
	while (curr != NULL) {
		node* next = curr->next;
		free(curr);
		curr = next;
	}
}
main() {
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		memset(visited, 0, sizeof(visited));
		bfs(a, b);
	}
}