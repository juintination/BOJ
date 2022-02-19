#include <stdio.h>
#include <stdlib.h>
int n, m, x1, y1, x2, y2, visited[300][300];
char arr[300][300];
typedef struct {
	int x, y, cnt;
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
void push(Queue* queue, int x, int y, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
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
	Queue queue, tmp;
	initQueue(&queue);
	initQueue(&tmp);
	push(&queue, x1 - 1, y1 - 1, 1);
	visited[x1 - 1][y1 - 1] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				if (arr[nx][ny] == '0') {
					push(&queue, nx, ny, p.cnt);
				}
				else if (arr[nx][ny] == '1') {
					push(&tmp, nx, ny, p.cnt + 1);
				}
				else {
					printf("%d", p.cnt);
					exit(0);
				}
			}
		}
		if (empty(&queue)) {
			while (!empty(&tmp)) {
				Point e = pop(&tmp);
				push(&queue, e.x, e.y, e.cnt);
			}
		}
	}
}
main() {
	scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
	char* str = (char*)malloc(sizeof(char) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
		}
	}
	free(str);
	bfs();
}