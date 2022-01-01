#include <stdio.h>
#include <stdlib.h>
int n, m, x[2], y[2], visited[20][20][20][20];
char arr[20][20];
typedef struct {
	int x1, y1, x2, y2, cnt;
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
void push(Queue* queue, int x1, int y1, int x2, int y2, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x1 = x1;
	now->point.y1 = y1;
	now->point.x2 = x2;
	now->point.y2 = y2;
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
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, x[0], y[0], x[1], y[1], 0);
	visited[x[0]][y[0]][x[1]][y[1]] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.cnt >= 10) break;
		for (int i = 0; i < 4; i++) {
			int nx1 = p.x1 + dx[i];
			int ny1 = p.y1 + dy[i];
			int nx2 = p.x2 + dx[i];
			int ny2 = p.y2 + dy[i];
			int coin = 0;
			if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m) {
				if (arr[nx1][ny1] == '#') {
					nx1 = p.x1;
					ny1 = p.y1;
				}
				coin++;
			}
			if (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m) {
				if (arr[nx2][ny2] == '#') {
					nx2 = p.x2;
					ny2 = p.y2;
				}
				coin++;
			}
			if (coin == 2 && !visited[nx1][ny1][nx2][ny2]) {
				visited[nx1][ny1][nx2][ny2] = 1;
				push(&queue, nx1, ny1, nx2, ny2, p.cnt + 1);
			}
			else if (coin == 1) {
				printf("%d", p.cnt + 1);
				exit(0);
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'o') {
				x[cnt] = i;
				y[cnt++] = j;
			}
		}
	}
	free(str);
	bfs();
	printf("-1");
}