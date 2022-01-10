#include <stdio.h>
#include <stdlib.h>
int n, x, y, arr[20][20], result = 0;
typedef struct Point {
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
int compare(const void* a, const void* b) {
	struct Point o1 = *(struct Point*)a;
	struct Point o2 = *(struct Point*)b;
	if (o1.x == o2.x) {
		return o1.y - o2.y;
	}
	return o1.x - o2.x;
}
Point bfs(Point e, int level) {
	Point list[400];
	Queue queue;
	initQueue(&queue);
	push(&queue, e.x, e.y, 0);
	int visited[20][20] = { 0 }, cnt = 0;
	visited[e.x][e.y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (arr[p.x][p.y] != 0 && level > arr[p.x][p.y]) {
			list[cnt++] = p;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && level >= arr[nx][ny]) {
				push(&queue, nx, ny, p.cnt + 1);
				visited[nx][ny] = 1;
			}
		}
	}
	Point next;
	next.x = x;
	next.y = y;
	qsort(list, cnt, sizeof(Point), compare);
	int min = 2147483647;
	for (int i = 0; i < cnt; i++) {
		if (list[i].cnt < min) {
			next = list[i];
			min = list[i].cnt;
		}
	}
	return next;
}
void babyshark() {
	Queue queue;
	initQueue(&queue);
	push(&queue, x, y, 0);
	int eat = 0, level = 2;
	while (!empty(&queue)) {
		Point p = bfs(pop(&queue), level);
		if (p.x == x && p.y == y) {
			printf("%d", result);
			exit(0);
		}
		else {
			push(&queue, p.x, p.y, p.cnt);
			arr[p.x][p.y] = 0;
			result += p.cnt;
			eat++;
			if (eat == level) {
				level++;
				eat = 0;
			}
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				x = i;
				y = j;
			}
		}
	}
	babyshark();
	printf("%d", result);
}