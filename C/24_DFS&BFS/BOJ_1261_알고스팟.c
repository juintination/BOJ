#include <stdio.h>
#include <stdlib.h>
int n, m, arr[100][100], map[100][100];
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
void bfs() {
	Queue queue, queue2;
	initQueue(&queue);
	initQueue(&queue2);
	push(&queue, 0, 0);
	map[0][0] = 0;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == -1) {
				if (arr[nx][ny] == 1) {
					push(&queue2, nx, ny);
					map[nx][ny] = map[p.x][p.y] + 1;
				}
				else {
					push(&queue, nx, ny);
					map[nx][ny] = map[p.x][p.y];
				}
			}
		}
		if (empty(&queue)) {
			queue = queue2;
			initQueue(&queue2);
		}
	}
}
main() {
	scanf("%d %d", &m, &n);
	char* str = (char*)malloc(sizeof(char) * m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
			map[i][j] = -1;
		}
	}
	free(str);
	bfs();
	printf("%d", map[n - 1][m - 1]);
}