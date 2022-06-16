#include <stdio.h>
#include <stdlib.h>
int n, m, r, cnt = 1, ** arr, * size, * visited, * sequence;
typedef struct node {
	int data;
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
void push(Queue* queue, int data) {
	node* now = (node*)malloc(sizeof(node));
	now->data = data;
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
int pop(Queue* queue) {
	int re;
	node* now;
	if (queue->count == 0) {
		return -1;
	}
	now = queue->front;
	re = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs(int value) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	initQueue(queue);
	push(queue, value);
	visited[value] = 1;
	sequence[value] = cnt++;
	while (!empty(queue)) {
		int p = pop(queue);
		for (int i = 0; i < size[p]; i++) {
			int e = arr[p][i];
			if (!visited[e]) {
				visited[e] = 1;
				sequence[e] = cnt++;
				push(queue, e);
			}
		}
	}
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
main() {
	scanf("%d %d %d", &n, &m, &r);
	arr = (int**)malloc(sizeof(int*) * (n + 1));
	size = (int*)malloc(sizeof(int) * (n + 1));
	visited = (int*)malloc(sizeof(int) * (n + 1));
	sequence = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int));
		size[i] = visited[i] = sequence[i] = 0;
	}
	int x, y;
	while (m--) {
		scanf("%d %d", &x, &y);
		arr[x] = (int*)realloc(arr[x], sizeof(int) * (size[x] + 1));
		arr[y] = (int*)realloc(arr[y], sizeof(int) * (size[y] + 1));
		arr[x][size[x]++] = y;
		arr[y][size[y]++] = x;
	}
	for (int i = 1; i <= n; i++) {
		qsort(arr[i], size[i], sizeof(int), compare);
	}
	bfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sequence[i]);
	}
}