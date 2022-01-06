#include <stdio.h>
#include <stdlib.h>
int n, m, k, arr[1000][1000], visited[1000][1000][11];
typedef struct {
	int x, y, cnt, breaked;
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
void push(Queue* queue, int x, int y, int cnt, int breaked) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->point.cnt = cnt;
	now->point.breaked = breaked;
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
	push(&queue, 0, 0, 1, 0);
	for (int i = 0; i <= k; i++) {
		visited[0][0][i] = 1;
	}
	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.x == n - 1 && p.y == m - 1) {
			printf("%d", p.cnt);
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny] == 1) {
					if (p.breaked < k && !visited[nx][ny][p.breaked + 1]) {
						visited[nx][ny][p.breaked + 1] = 1;
						push(&queue, nx, ny, p.cnt + 1, p.breaked + 1);
					}
				}
				else if (arr[nx][ny] == 0) {
					if (!visited[nx][ny][p.breaked]) {
						visited[nx][ny][p.breaked] = 1;
						push(&queue, nx, ny, p.cnt + 1, p.breaked);
					}
				}
			}
		}
	}
}
main() {
	scanf("%d %d %d", &n, &m, &k);
	char* str = (char*)malloc(sizeof(char) * m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	free(str);
	bfs();
	printf("-1");
}