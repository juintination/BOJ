#include <stdio.h>
#include <stdlib.h>
#define math_min(a, b) a < b ? a : b
int n, m, size = 0, **arr, **tmp, *directed, min = 2147483647;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
typedef struct {
	int x, y, num;
} Point;
Point* list;
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
void push(Queue* queue, int x, int y, int num) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->point.num = num;
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
void searched(Point cctv, int i) {
	Queue queue;
	initQueue(&queue);
	push(&queue, cctv.x, cctv.y, cctv.num);
	while (!empty(&queue)) {
		Point p = pop(&queue);
		int nx = p.x + dx[i];
		int ny = p.y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (tmp[nx][ny] == 0) {
				tmp[nx][ny] = -1;
				push(&queue, nx, ny, cctv.num);
			}
			else if (tmp[nx][ny] != 6) {
				push(&queue, nx, ny, cctv.num);
			}
		}
	}
}
void observed(Point cctv, int d) {
	if (cctv.num == 1) {
		searched(cctv, d);
	}
	else if (cctv.num == 2) {
		if (d == 0) {
			searched(cctv, 0);
			searched(cctv, 2);
		}
		else if (d == 2) {
			searched(cctv, 1);
			searched(cctv, 3);
		}
	}
	else if (cctv.num == 3) {
		searched(cctv, d);
		searched(cctv, (d + 1) % 4);
	}
	else if (cctv.num == 4) {
		searched(cctv, d);
		searched(cctv, (d + 1) % 4);
		searched(cctv, (d + 2) % 4);
	}
	else if (cctv.num == 5) {
		for (int i = 0; i <= 3; i++) {
			searched(cctv, i);
		}
	}
}
void dfs(int dpth) {
	if (dpth == size) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < size; i++) {
			observed(list[i], directed[i]);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0) {
					cnt++;
				}
			}
		}
		min = math_min(min, cnt);
		return;
	}
	int cctvNum = list[dpth].num;
	for (int i = 0; i < 4; i++) {
		directed[dpth] = i;
		dfs(dpth + 1);
		if (cctvNum == 2) {
			i++;
		}
		else if (cctvNum == 5) {
			break;
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(sizeof(int*) * n);
	tmp = (int**)malloc(sizeof(int*) * n);
	list = (Point*)malloc(sizeof(Point) * (n * m));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * m);
		tmp[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (0 < arr[i][j] && arr[i][j] < 6) {
				list[size].x = i;
				list[size].y = j;
				list[size++].num = arr[i][j];
			}
		}
	}
	directed = (int*)malloc(sizeof(int) * size);
	dfs(0);
	printf("%d", min);
}