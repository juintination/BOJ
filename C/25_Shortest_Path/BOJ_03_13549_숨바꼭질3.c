#include <stdio.h>
#include <stdlib.h>
#define heap_size 100000
int n, k, visited[100001];
typedef struct {
	int x, cnt;
} Point;
void swap(Point* a, Point* b) {
	Point temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct priorityQueue {
	Point heap[heap_size];
	int count;
} priorityQueue;
void initQueue(priorityQueue* queue) {
	queue->count = 0;
}
void push(priorityQueue* queue, int x, int cnt) {
	if (queue->count >= heap_size) return;
	queue->heap[queue->count].x = x;
	queue->heap[queue->count].cnt = cnt;
	int now = queue->count;
	int parent = (queue->count - 1) / 2;
	while (now > 0 && queue->heap[parent].cnt > queue->heap[now].cnt) {
		swap(&queue->heap[now], &queue->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	queue->count++;
}
Point pop(priorityQueue* queue) {
	Point re = queue->heap[0];
	queue->count--;
	queue->heap[0] = queue->heap[queue->count];
	int now = 0, left = 1, right = 2;
	int target = now;
	while (left < queue->count) {
		if (queue->heap[target].cnt > queue->heap[left].cnt) target = left;
		if (queue->heap[target].cnt > queue->heap[right].cnt && right < queue->count) target = right;
		if (target == now) break;
		else {
			swap(&queue->heap[now], &queue->heap[target]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}
	return re;
}
int empty(priorityQueue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs() {
	priorityQueue queue;
	initQueue(&queue);
	push(&queue, n, 0);
	while (!empty(&queue)) {
		Point p = pop(&queue);
		visited[p.x] = 1;
		if (p.x == k) {
			printf("%d", p.cnt);
			exit(0);
		}
		int dx[] = { p.x - 1, p.x + 1, p.x * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (nx >= 0 && nx <= 100000 && !visited[nx]) {
				if (nx == p.x * 2) {
					push(&queue, nx, p.cnt);
				}
				else {
					push(&queue, nx, p.cnt + 1);
				}
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	bfs();
}