#include <stdio.h>
#include <stdlib.h>
int n, m, x, y, visited[50][50], flooded[50][50];
char arr[50][50];
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
Queue water;
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
	Queue queue;
	initQueue(&queue);
	push(&queue, x, y, 0);
	visited[x][y] = 1;
	int turn = 0, watered = 0;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		int size = water.count;
		while (size--) {
			if (turn > p.cnt) break;
			Point w = pop(&water);
			for (int i = 0; i < 4; i++) {
				int nx = w.x + dx[i];
				int ny = w.y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !flooded[nx][ny]) {
					if (arr[nx][ny] == '.' || arr[nx][ny] == 'S') {
						push(&water, nx, ny, 0);
						flooded[nx][ny] = 1;
						arr[nx][ny] = '*';
					}
				}
			}
			watered = 1;
		}
		if (watered) {
			watered = 0;
			turn++;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
				if (arr[nx][ny] == 'D') {
					printf("%d", p.cnt + 1);
					exit(0);
				}
				else if (arr[nx][ny] == '.') {
					push(&queue, nx, ny, p.cnt + 1);
					visited[nx][ny] = 1;
				}
			}
		}
	}
}
main() {
	initQueue(&water);
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == '*') {
				push(&water, i, j, 0);
				flooded[i][j] = 1;
			}
			else if (arr[i][j] == 'S') {
				x = i;
				y = j;
			}
		}
	}
	free(str);
	bfs();
	printf("KAKTUS");
}