#include <stdio.h>
#include <stdlib.h>
int start, goal, cnt = 0, sieved[10000], visited[10000];
int* result;
typedef struct {
	int x, cnt;
} Point;
typedef struct node {
	Point point;
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
void push(Queue* queue, int x, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.cnt = cnt;
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
Point pop(Queue* queue) {
	Point re;
	node* now;
	now = queue->front;
	re = now->point;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void eratosthenes() {
	sieved[1] = 1;
	for (int i = 2; i < 100; i++) {
		if (sieved[i]) continue;
		for (int j = i * i; j < 10000; j += i) {
			sieved[j] = 1;
		}
	}
}
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, start, 0);
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.x == goal) {
			result[cnt++] = p.cnt;
			return;
		}
		int tmp = p.x;
		int digit[4] = { 0 };
		int dx[] = { 1000, 100, 10, 1 };
		for (int i = 0; i < 4; i++) {
			digit[i] = tmp / dx[i];
			tmp %= dx[i];
		}
		for (int i = 0; i < 4; i++) {
			tmp = p.x - digit[i] * dx[i];
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) continue;
				int nx = tmp + dx[i] * j;
				if (!sieved[nx] && !visited[nx]) {
					push(&queue, nx, p.cnt + 1);
					visited[nx] = 1;
				}
			}
		}
	}
	result[cnt++] = -1;
}
main() {
	int t;
	scanf("%d", &t);
	result = (int*)malloc(sizeof(int) * t);
	eratosthenes();
	while (t--) {
		scanf("%d %d", &start, &goal);
		for (int i = 1000; i < 10000; i++) {
			visited[i] = 0;
		}
		bfs();
	}
	for (int i = 0; i < cnt; i++) {
		if (result[i] != -1) printf("%d\n", result[i]);
		else printf("Impossible\n");
	}
}