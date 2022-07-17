#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define heap_size 50000
#define math_min(a, b) a < b ? a : b
int n, m, t, * min, * visited;
const int INF = INT_MAX / 3;
typedef struct {
	int x, cost;
} Point;
typedef struct node {
	Point point;
	struct node* next;
} node;
void add(node* target, int x, int cost) {
	node* now = (node*)malloc(sizeof(node));
	now->point.x = x;
	now->point.cost = cost;
	now->next = target->next;
	target->next = now;
	return;
}
node* list[2001];
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
void push(priorityQueue* queue, int x, int cost) {
	if (queue->count >= heap_size) return;
	queue->heap[queue->count].x = x;
	queue->heap[queue->count].cost = cost;
	int now = queue->count;
	int parent = (queue->count - 1) / 2;
	while (now > 0 && queue->heap[parent].cost > queue->heap[now].cost) {
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
		if (queue->heap[target].cost > queue->heap[left].cost) target = left;
		if (queue->heap[target].cost > queue->heap[right].cost && right < queue->count) target = right;
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
int dijkstra(int from, int to) {
	priorityQueue queue;
	initQueue(&queue);
	push(&queue, from, 0);
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
		min[i] = INF;
	}
	min[from] = 0;
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (visited[p.x]) continue;
		visited[p.x] = 1;
		node* curr = list[p.x]->next;
		while (curr != NULL) {
			Point e = curr->point;
			int cost = e.cost + p.cost;
			if (min[e.x] > cost) {
				min[e.x] = cost;
				push(&queue, e.x, cost);
			}
			curr = curr->next;
		}
	}
	return min[to];
}
main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &t);
		min = (int*)malloc(sizeof(int) * (n + 1));
		visited = (int*)malloc(sizeof(int) * (n + 1));
		for (int i = 1; i <= n; i++) {
			list[i] = (node*)malloc(sizeof(node));
			list[i]->next = NULL;
		}
		int s, g, h, x;
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			add(list[a], b, d);
			add(list[b], a, d);
		}
		priorityQueue candidate;
		initQueue(&candidate);
		for (int i = 0; i < t; i++) {
			scanf("%d", &x);
			int sghx = dijkstra(s, g) + dijkstra(g, h) + dijkstra(h, x);
			int shgx = dijkstra(s, h) + dijkstra(h, g) + dijkstra(g, x);
			int tmp = math_min(sghx, shgx);
			if (tmp == dijkstra(s, x)) {
				push(&candidate, 0, x);
			}
		}
		while (!empty(&candidate)) {
			printf("%d ", pop(&candidate).cost);
		}
		printf("\n");
	}
}