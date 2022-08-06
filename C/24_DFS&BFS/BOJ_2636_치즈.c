#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, cnt = 0, **arr, **visited;
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
	for (int i = 0; i < n; i++) {
		memset(visited[i], 0, sizeof(int) * m);
	}
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				if (arr[nx][ny] == 0) {
					push(&queue, nx, ny);
				}
				else {
					arr[nx][ny] = 0;
					cnt--;
				}
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(sizeof(int*) * n);
	visited = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * m);
		visited[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			cnt = arr[i][j] == 1 ? cnt + 1 : cnt;
		}
	}
	int preCnt = cnt, hour = 1;
	while (1) {
		bfs(0, 0);
		if (!cnt) {
			printf("%d\n%d", hour, preCnt);
			break;
		}
		preCnt = cnt;
		hour++;
	}
}