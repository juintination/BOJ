#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define math_min(a, b) a < b ? a : b
int w, h, mirror[4][100][100], min = INT_MAX;
int start_x, start_y, end_x, end_y;
char** arr;
typedef struct {
	int x, y, i, cnt;
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
void push(Queue* queue, int x, int y, int i, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->point.i = i;
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
	push(&queue, start_x, start_y, -5, -1);
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				mirror[k][i][j] = INT_MAX;
			}
		}
	}
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.x == end_x && p.y == end_y) {
			min = math_min(min, p.cnt);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w && arr[nx][ny] != '*') {
				if (p.i == i) {
					if (p.cnt < mirror[i][nx][ny]) {
						mirror[i][nx][ny] = p.cnt;
						push(&queue, nx, ny, i, p.cnt);
					}
				}
				else if (abs(p.i - i) != 2) {
					if (p.cnt + 1 < mirror[i][nx][ny]) {
						mirror[i][nx][ny] = p.cnt + 1;
						push(&queue, nx, ny, i, p.cnt + 1);
					}
				} 
			}
		}
	}
}
main() {
	int first = 1;
	scanf("%d %d", &w, &h);
	char* str = (char*)malloc(sizeof(char) * w);
	arr = (char**)malloc(sizeof(char*) * h);
	for (int i = 0; i < h; i++) {
		arr[i] = (char*)malloc(sizeof(char) * w);
		scanf("%s", str);
		for (int j = 0; j < w; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'C') {
				if (first) {
					start_x = i;
					start_y = j;
					first = !first;
				}
				else {
					end_x = i;
					end_y = j;
				}
			}
		}
	}
	bfs();
	printf("%d", min);
}