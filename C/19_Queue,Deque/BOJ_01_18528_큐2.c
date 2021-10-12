#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int size(Queue* queue) {
	return (queue->count);
}

int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}

int front(Queue* queue) {
	if (queue->count == 0) return -1;
	else return queue->front->data;
}

int back(Queue* queue) {
	if (queue->count == 0) return -1;
	else return queue->rear->data;
}

main() {
	int n, cnt = 0;
	char order[6];
	scanf("%d", &n);
	Queue q;
	initQueue(&q);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &order);
		if (order[0] == 'p') {
			if (order[1] == 'u') {
				int x;
				scanf("%d", &x);
				push(&q, x);
			}
			else result[cnt++] = pop(&q);
		}
		else if (order[0] == 's') {
			result[cnt++] = size(&q);
		}
		else if (order[0] == 'e') {
			result[cnt++] = empty(&q);
		}
		else if (order[0] == 'f') {
			result[cnt++] = front(&q);
		}
		else if (order[0] == 'b') {
			result[cnt++] = back(&q);
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}