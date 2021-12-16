#include <stdio.h>
#include <stdlib.h>
int n, k, arr[100001], cnt = 0, min = 2147483647;
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
void bfs(int idx) {
	Queue queue;
	initQueue(&queue);
	push(&queue, idx);
	while (!empty(&queue)) {
		int x = pop(&queue);
		if (x == k && min >= arr[k]) {
			min = arr[k];
			cnt++;
		}
		int dx[] = { x - 1, x + 1, x * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (nx >= 0 && nx <= 100000 && (arr[nx] == 0 || arr[nx] == arr[x] + 1)) {
				push(&queue, nx);
				arr[nx] = arr[x] + 1;
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	bfs(n);
	printf("%d\n%d", min, cnt);
}