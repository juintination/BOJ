#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, **arr, **visited;
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
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}
int bfs(int min, int max) {
	Queue queue;
	initQueue(&queue);
	push(&queue, 0, 0);
	visited[0][0] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.x == n - 1 && p.y == n - 1) {
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
				if (min <= arr[nx][ny] && arr[nx][ny] <= max) {
					push(&queue, nx, ny);
					visited[nx][ny] = 1;
				}
			}
		}
	}
	return 0;
}
main() {
	scanf("%d", &n);
	int max = 0, min = 200;
	arr = (int**)malloc(sizeof(int*) * n);
	visited = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		visited[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			max = math_max(max, arr[i][j]);
			min = math_min(min, arr[i][j]);
		}
	}
	int left = 0, right = max - min, result = right;
	while (left <= right) {
		int mid = (right + left) / 2;
		int tst = 0;
		for (int idx = min; idx <= max; idx++) {
			if (idx <= arr[0][0] && arr[0][0] <= idx + mid) {
				initVisited();
				if (bfs(idx, idx + mid)) {
					tst = !tst;
					break;
				}
			}
		}
		if (tst) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d", result);
}