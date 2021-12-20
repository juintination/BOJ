#include <stdio.h>
#include <stdlib.h>
int l, arr[300][300], visited[300][300];
typedef struct {
	int x, y;
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
void push(Queue* queue, int x, int y) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
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
void bfs(int x, int y) {
	Queue queue;
	initQueue(&queue);
	push(&queue, x, y);
	visited[x][y] = 1;
	int dx[] = { -1, 1, -2, 2, -1, 1, -2, 2 };
	int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		x = p.x;
		y = p.y;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = 1;
				arr[nx][ny] = arr[x][y] + 1;
				push(&queue, nx, ny);
			}
		}
	}
}
main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &l);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				arr[i][j] = visited[i][j] = 0;
			}
		}
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		bfs(a, b);
		printf("%d\n", arr[c][d]);
	}
}