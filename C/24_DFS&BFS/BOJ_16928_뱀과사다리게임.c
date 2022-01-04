#include <stdio.h>
#include <stdlib.h>
int n, m, result, arr[101], cnt[101], visited[101];
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
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, 1);
	visited[1] = 1;
	while (!empty(&queue)) {
		int tmp = pop(&queue);
		if (tmp == 100) {
			result = cnt[100];
			return;
		}
		for (int i = 6; i > 0; i--) {
			int e = tmp + i;
			if (e <= 100 && !visited[e]) {
				if (arr[e] != 0) {
					if (!visited[arr[e]]) {
						push(&queue, arr[e]);
						visited[arr[e]] = 1;
						cnt[arr[e]] = cnt[tmp] + 1;
					}
				}
				else {
					push(&queue, e);
					visited[e] = 1;
					cnt[e] = cnt[tmp] + 1;
				}
			}
		}
	}
}
main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n + m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x] = y;
	}
	bfs();
	printf("%d", result);
}