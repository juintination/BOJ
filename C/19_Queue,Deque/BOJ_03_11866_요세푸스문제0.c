#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

typedef struct Queue {
	node* front;
	node* rear;
	int cnt;
} Queue;

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->cnt = 0;
}

void push(Queue* queue, int data) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
	now->next = NULL;
	if (queue->cnt == 0) {
		queue->front = now;
	}
	else {
		queue->rear->next = now;
	}
	queue->rear = now;
	queue->cnt++;
}

int pop(Queue* queue) {
	node* now;
	if (queue->cnt == 0) {
		return -1;
	}
	now = queue->front;
	int x = now->data;
	queue->front = now->next;
	free(now);
	queue->cnt--;
	return x;
}

int front(Queue* queue) {
	if (queue->cnt == 0) return -1;
	else return queue->front->data;
}

int back(Queue* queue) {
	if (queue->cnt == 0) return -1;
	else return queue->rear->data;
}

main() {
	int n = 0, k = 0, cnt = 0;
	scanf("%d %d", &n, &k);
	Queue q;
	initQueue(&q);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 1; i <= n; i++) push(&q, i);
	while (q.cnt != 0) {
		for (int i = 0; i < k - 1; i++) {
			push(&q, pop(&q));
		}
		result[cnt++] = pop(&q);
	}
	printf("<");
	for (int i = 0; i < n - 1; i++) printf("%d, ", result[i]);
	printf("%d>", result[n - 1]);
}