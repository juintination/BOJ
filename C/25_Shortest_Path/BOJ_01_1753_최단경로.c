#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define heap_size 300000
int n, m, k, * min;
const int INF = INT_MAX;
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
node* list[20001];
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
void dijkstra() {
	priorityQueue queue;
	initQueue(&queue);
	push(&queue, k, 0);
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (min[p.x] < p.cost) continue;
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
}
main() {
	scanf("%d %d %d", &n, &m, &k);
	min = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		min[i] = INF;
	}
	min[k] = 0;
	for (int i = 1; i <= n; i++) {
		list[i] = (node*)malloc(sizeof(node));
		list[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(list[u], v, w);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		if (min[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", min[i]);
		}
	}
}