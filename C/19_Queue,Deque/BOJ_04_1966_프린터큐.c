#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int idx;
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

void push(Queue* queue, int data, int x) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
	now->idx = x;
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

node pop(Queue* queue) {
	node* re;
	node* now;
	if (queue->count == 0) {
		printf("queue->count == 0\n");
	}
	now = queue->front;
	re = now;
	queue->front = now->next;
	queue->count--;
	return *re;
}

main() {
	int t, n, m, tst = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		Queue q;
		initQueue(&q);
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			int importance;
			scanf("%d", &importance);
			if (j != m) push(&q, importance, 0);
			else push(&q, importance, 1);
		}
		int cnt = 1;
		while (1) {
			int max = 0;
			for (int j = 0; j < q.count; j++) {
				if (q.front->data > max) {
					max = q.front->data;
					node tmp = pop(&q);
					push(&q, tmp.data, tmp.idx);
				}
				else {
					node tmp = pop(&q);
					push(&q, tmp.data, tmp.idx);
				}
			}
			while (q.front->data != max) {
				node tmp = pop(&q);
				push(&q, tmp.data, tmp.idx);
			}
			if (q.front->idx == 1) {
				break;
			}
			pop(&q);
			max = 0;
			cnt++;
		}
		result[tst++] = cnt;
	}
	for (int i = 0; i < tst; i++) {
		printf("%d\n", result[i]);
	}
}