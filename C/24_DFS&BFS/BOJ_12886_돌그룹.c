#include <stdio.h>
#include <stdlib.h>
int a, b, c, visited[1001][1001];
typedef struct {
	int a, b, c;
} Stone;
typedef struct node {
	Stone stone;
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
void push(Queue* queue, int a, int b, int c) {
	node* now = (node*)malloc(sizeof(node));
	now->stone.a = a;
	now->stone.b = b;
	now->stone.c = c;
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
Stone pop(Queue* queue) {
	Stone re;
	node* now;
	now = queue->front;
	re = now->stone;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs(int a, int b, int c) {
	Queue queue;
	initQueue(&queue);
	push(&queue, a, b, c);
	while (!empty(&queue)) {
		Stone s = pop(&queue);
		a = s.a;
		b = s.b;
		c = s.c;
		if (a == b && b == c) {
			printf("1");
			exit(0);
		}
		if (a != b) {
			int na = a > b ? a - b : a * 2;
			int nb = a > b ? b * 2 : b - a;
			if (na <= 1000 && nb <= 1000 && !visited[na][nb]) {
				push(&queue, na, nb, c);
				visited[na][nb] = 1;
				visited[nb][na] = 1;
			}
		}
		if (b != c) {
			int nb = b > c ? b - c : b * 2;
			int nc = b > c ? c * 2 : c - b;
			if (nb <= 1000 && nc <= 1000 && !visited[nb][nc]) {
				push(&queue, a, nb, nc);
				visited[nb][nc] = 1;
				visited[nc][nb] = 1;
			}
		}
		if (c != a) {
			int nc = c > a ? c - a : c * 2;
			int na = c > a ? a * 2 : a - c;
			if (na <= 1000 && nc <= 1000 && !visited[na][nc]) {
				push(&queue, na, b, nc);
				visited[na][nc] = 1;
				visited[nc][na] = 1;
			}
		}
	}
}
main() {
	scanf("%d %d %d", &a, &b, &c);
	bfs(a, b, c);
	printf("0");
}