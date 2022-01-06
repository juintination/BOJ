#include <stdio.h>
#include <stdlib.h>
int n, m, arr[1000][1000], district[1000][1000], map[1000000];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
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
void bfs(int x, int y, int idx) {
	Queue queue;
	initQueue(&queue);
	push(&queue, x, y);
	district[x][y] = idx;
	int cnt = 0;
	while (!empty(&queue)) {
		Point p = pop(&queue);
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
				if (district[nx][ny] == 0) {
					district[nx][ny] = idx;
					push(&queue, nx, ny);
				}
			}
		}
	}
	map[idx] = cnt;
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	free(str);
	int idx = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && district[i][j] == 0) {
				bfs(i, j, idx++);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				int used[4] = { 0 };
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
						int d = district[nx][ny];
						if (d > 0) {
							int tst = 1;
							for (int l = 0; l < 4; l++) {
								if (d == used[l]) {
									tst = !tst;
									break;
								}
							}
							if (tst) {
								used[k] = d;
								arr[i][j] += map[d];
							}
						}
					}
				}
				printf("%d", arr[i][j] % 10);
			}
			else if (arr[i][j] == 0) {
				printf("0");
			}
		}
		printf("\n");
	}
}