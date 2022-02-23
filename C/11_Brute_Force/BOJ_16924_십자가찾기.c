#include <stdio.h>
#include <stdlib.h>
int n, m, **visited;
char** arr;
typedef struct {
	int x, y, s;
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
void push(Queue* queue, int x, int y, int s) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->point.s = s;
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
int size(Queue* queue) {
	return (queue->count);
}
main() {
	scanf("%d %d", &n, &m);
	arr = (char**)malloc(sizeof(char*) * n);
	visited = (int**)malloc(sizeof(int*) * n);
	char* str = (char*)malloc(sizeof(char) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		arr[i] = (char*)malloc(sizeof(char) * m);
		visited[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			visited[i][j] = 0;
		}
	}
	Queue queue;
	initQueue(&queue);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int size = 0;
			if (arr[i][j] == '*') {
				int k = 1;
				while (1) {
					if (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) {
						if (arr[i - k][j] == '*' && arr[i + k][j] == '*' && arr[i][j - k] == '*' && arr[i][j + k] == '*') {
							size = k++;
						}
						else break;
					}
					else break;
				}
			}
			if (size > 0) {
				push(&queue, i + 1, j + 1, size);
				visited[i][j] = 1;
				for (int k = 1; k <= size; k++) {
					visited[i - k][j] = visited[i + k][j] = visited[i][j - k] = visited[i][j + k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*' && !visited[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	int sum = 0, tmp = size(&queue);
	for (int i = 0; i < tmp; i++) {
		Point e = pop(&queue);
		sum += e.s;
		push(&queue, e.x, e.y, e.s);
	}
	printf("%d\n", sum);
	for (int i = 0; i < tmp; i++) {
		Point p = pop(&queue);
		for (int j = p.s; j >= 1; j--) {
			printf("%d %d %d\n", p.x, p.y, j);
		}
	}
}