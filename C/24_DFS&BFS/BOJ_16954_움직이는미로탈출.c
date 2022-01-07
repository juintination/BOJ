#include <stdio.h>
#include <stdlib.h>
int visited[8][8];
char arr[8][8];
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
void down() {
	for (int i = 7; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			if (i == 0) {
				arr[i][j] = '.';
			}
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
}
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, 7, 0);
	int dx[] = { -1, 0, 1, 0, 0, -1, 1, -1, 1 };
	int dy[] = { 0, -1, 0, 1, 0, -1, -1, 1, 1 };
	while (!empty(&queue)) {
		int size = queue.count;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++) {
			Point p = pop(&queue);
			if (arr[p.x][p.y] == '#') continue;
			if (p.x == 0) {
				printf("1");
				exit(0);
			}
			for (int j = 0; j < 9; j++) {
				int nx = p.x + dx[j];
				int ny = p.y + dy[j];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny] && arr[nx][ny] == '.') {
					push(&queue, nx, ny);
					visited[nx][ny] = 1;
				}
			}
		}
		down();
	}
}
main() {
	char* str = (char*)malloc(sizeof(char) * 8);
	for (int i = 0; i < 8; i++) {
		scanf("%s", str);
		for (int j = 0; j < 8; j++) {
			arr[i][j] = str[j];
		}
	}
	free(str);
	bfs();
	printf("0");
}