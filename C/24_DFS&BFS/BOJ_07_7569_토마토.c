#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
int n, m, h, arr[100][100][100];
typedef struct {
	int x, y, z;
} Tomato;
typedef struct node {
	Tomato tomato;
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
void push(Queue* queue, int z, int x, int y) {
	node* now = (node*)malloc(sizeof(node));
	now->tomato.z = z;
	now->tomato.x = x;
	now->tomato.y = y;
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
Tomato pop(Queue* queue) {
	Tomato re;
	node* now;
	now = queue->front;
	re = now->tomato;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs(int x, int y, int z) {
	Queue queue;
	initQueue(&queue);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[i][j][k] == 1) {
					push(&queue, i, j, k);
				}
			}
		}
	}
	int dx[] = { -1, 0, 1, 0, 0, 0 };
	int dy[] = { 0, -1, 0, 1, 0, 0 };
	int dz[] = { 0, 0, 0, 0, -1, 1 };
	while (!empty(&queue)) {
		Tomato t = pop(&queue);
		z = t.z;
		y = t.y;
		x = t.x;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h && arr[nz][nx][ny] == 0) {
				arr[nz][nx][ny] = arr[z][x][y] + 1;
				push(&queue, nz, nx, ny);
			}
		}
	}
}
main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &arr[i][j][k]);
			}
		}
	}
	bfs(0, 0, 0);
	int max = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[i][j][k] == 0) {
					printf("-1");
					exit(0);
				}
				max = math_max(max, arr[i][j][k]);
			}
		}
	}
	printf("%d", max - 1);
}