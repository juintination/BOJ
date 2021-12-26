#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
int n, m, wall = 3, virus = 0, result = 0, arr[8][8], visited[8][8];
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
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void add(node* target, int x, int y) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->next = target->next;
	target->next = now;
	return;
}
node* list;
void bfs() {
	Queue queue;
	initQueue(&queue);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	int size = virus;
	node* curr = list->next;
	while (curr != NULL) {
		if (!visited[curr->point.x][curr->point.y]) {
			push(&queue, curr->point.x, curr->point.y);
			visited[curr->point.x][curr->point.y] = 1;
		}
		curr = curr->next;
	}
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] == 0) {
				push(&queue, nx, ny);
				visited[nx][ny] = 1;
				size++;
			}
		}
	}
	int tmp = n * m - wall - size;
	result = math_max(result, tmp);
}
void dfs(int dpth) {
	if (dpth == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				dfs(dpth + 1);
				arr[i][j] = 0;
			}
		}
	}
}
main() {
	int cnt = 0;
	scanf("%d %d", &n, &m);
	list = (node*)malloc(sizeof(node));
	list->next = NULL;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				add(list, i, j);
				virus++;
			}
			else if (arr[i][j] == 1) {
				wall++;
			}
		}
	}
	dfs(0);
	printf("%d", result);
}