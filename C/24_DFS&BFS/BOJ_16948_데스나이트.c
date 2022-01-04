#include <stdio.h>
#include <stdlib.h>
int n, r1, c1, r2, c2, arr[200][200], visited[200][200];
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
	int dx[] = { -2, -2, 0, 0, 2, 2 };
	int dy[] = { -1, 1, -2, 2, -1, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.x == r2 && p.y == c2) {
			printf("%d", arr[p.x][p.y]);
			exit(0);
		}
		for (int i = 0; i < 6; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = 1;
				arr[nx][ny] = arr[p.x][p.y] + 1;
				push(&queue, nx, ny);
			}
		}
	}
}
main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	bfs(r1, c1);
	printf("-1");
}