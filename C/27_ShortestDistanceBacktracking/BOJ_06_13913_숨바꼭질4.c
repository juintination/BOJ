#include <stdio.h>
#include <stdlib.h>
int n, k, dp[100001], parent[100001];
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
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, n);
	while (!empty(&queue)) {
		int x = pop(&queue);
		if (x == k) break;
		int dx[] = { x - 1, x + 1, x * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (0 <= nx && nx <= 100000 && dp[nx] == 0) {
				push(&queue, nx);
				dp[nx] = dp[x] + 1;
				parent[nx] = x;
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	bfs();
	printf("%d\n", dp[k]);
	int* stack = (int*)malloc(sizeof(int) * (dp[k] + 1));
	int idx = -1;
	while (k != n) {
		stack[++idx] = k;
		k = parent[k];
	}
	stack[++idx] = n;
	while (idx >= 0) {
		printf("%d ", stack[idx--]);
	}
}