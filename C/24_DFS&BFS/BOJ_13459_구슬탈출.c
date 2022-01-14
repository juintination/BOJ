#include <stdio.h>
#include <stdlib.h>
int n, m, rx, ry, bx, by, visited[10][10][10][10];
char arr[10][10];
typedef struct {
	int rx, ry, bx, by, cnt;
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
void push(Queue* queue, int rx, int ry, int bx, int by, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.rx = rx;
	now->point.ry = ry;
	now->point.bx = bx;
	now->point.by = by;
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
typedef struct {
	int x, y, cnt;
} Marble;
Marble tilt(int x, int y, int cnt, int i) {
	Marble moved;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (arr[x + dx[i]][y + dy[i]] != '#' && arr[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		cnt++;
	}
	moved.x = x;
	moved.y = y;
	moved.cnt = cnt;
	return moved;
}
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, rx, ry, bx, by, 0);
	visited[rx][ry][bx][by] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		for (int i = 0; i < 4; i++) {
			Marble nr = tilt(p.rx, p.ry, 0, i);
			Marble nb = tilt(p.bx, p.by, 0, i);
			if (arr[nb.x][nb.y] == 'O') continue;
			if (arr[nr.x][nr.y] == 'O') {
				printf("1");
				exit(0);
			}
			if (nr.x == nb.x && nr.y == nb.y) {
				if (nr.cnt > nb.cnt) {
					nr.x -= dx[i];
					nr.y -= dy[i];
				}
				else {
					nb.x -= dx[i];
					nb.y -= dy[i];
				}
			}
			if (!visited[nr.x][nr.y][nb.x][nb.y]) {
				visited[nr.x][nr.y][nb.x][nb.y] = 1;
				push(&queue, nr.x, nr.y, nb.x, nb.y, p.cnt + 1);
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (arr[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}
	free(str);
	bfs();
	printf("0");
}