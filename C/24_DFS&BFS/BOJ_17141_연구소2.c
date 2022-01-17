#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, m, wall = 0, min = 2147483647, arr[50][50], visited[50][50], *virus_visited, virus_cnt = 0;
typedef struct {
	int x, y, cnt;
} Point;
Point* virus_list;
Point virus[10];
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
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void add(node* target, int x, int y, int cnt) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.y = y;
	now->point.cnt = cnt;
	now->next = target->next;
	target->next = now;
	return;
}
node* list;
void bfs() {
	Queue queue;
	initQueue(&queue);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		Point v = virus[i];
		push(&queue, v.x, v.y, 0);
		visited[v.x][v.y] = 1;
	}
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	int size = m, cnt = 0;
	while (!empty(&queue)) {
		Point p = pop(&queue);
		cnt = math_max(cnt, p.cnt);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == 2)) {
					push(&queue, nx, ny, p.cnt + 1);
					visited[nx][ny] = 1;
					size++;
				}
			}
		}
	}
	int tmp = n * n - wall - size;
	if (tmp == 0) {
		min = math_min(min, cnt);
	}
}
void dfs(int dpth, int idx) {
	if (dpth == m) {
		bfs();
		return;
	}
	for (int i = idx; i < virus_cnt; i++) {
		virus[dpth] = virus_list[i];
		dfs(dpth + 1, i + 1);
	}
}
main() {
	scanf("%d %d", &n, &m);
	list = (node*)malloc(sizeof(node));
	list->next = NULL;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				add(list, i, j, 0);
				virus_cnt++;
			}
			else if (arr[i][j] == 1) {
				wall++;
			}
		}
	}
	virus_visited = (int*)malloc(sizeof(int) * virus_cnt);
	for (int i = 0; i < virus_cnt; i++) {
		virus_visited[i] = 0;
	}
	virus_list = (Point*)malloc(sizeof(Point) * virus_cnt);
	node* curr = list->next;
	int i = 0;
	while (curr != NULL) {
		Point p = curr->point;
		virus_list[i] = p;
		curr = curr->next;
		i++;
	}
	dfs(0, 0);
	if (min == 2147483647) {
		printf("-1");
	}
	else {
		printf("%d", min);
	}
}