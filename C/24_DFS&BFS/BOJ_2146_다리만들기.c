#include <stdio.h>
#include <stdlib.h>
#define math_min(a, b) a < b ? a : b
int n, min, arr[100][100], num[100][100], visited[100][100];
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
void dfs(int x, int y, int cnt) {
	visited[x][y] = 1;
	num[x][y] = cnt;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == 1) {
			dfs(nx, ny, cnt);
		}
	}
}
void bfs(int x, int y) {
	Queue queue;
	initQueue(&queue);
	push(&queue, x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	visited[x][y] = 1;
	int idx = num[x][y];
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		x = p.x;
		y = p.y;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && num[nx][ny] != idx) {
				visited[nx][ny] = 1;
				if (num[nx][ny] == 0) {
					arr[nx][ny] = arr[x][y] + 1;
					push(&queue, nx, ny);
				}
				else {
					min = math_min(min, arr[x][y] - 1);
				}
			}
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				dfs(i, j, cnt++);
			}
		}
	}
	min = 2147483647;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i][j] > 0) {
				bfs(i, j);
			}
		}
	}
	printf("%d", min);
}