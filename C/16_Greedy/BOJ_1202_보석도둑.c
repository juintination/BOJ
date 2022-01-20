#include <stdio.h>
#include <stdlib.h>
#define heap_size 300000
typedef struct {
	int m, v;
} point;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct priorityQueue {
	int heap[heap_size];
	int count;
} priorityQueue;
void initQueue(priorityQueue* queue) {
	queue->count = 0;
}
void push(priorityQueue* queue, int data) {
	if (queue->count >= heap_size) return;
	queue->heap[queue->count] = data;
	int now = queue->count;
	int parent = (queue->count - 1) / 2;
	while (now > 0 && queue->heap[parent] < queue->heap[now]) {
		swap(&queue->heap[now], &queue->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	queue->count++;
}
int pop(priorityQueue* queue) {
	int re = queue->heap[0];
	queue->count--;
	queue->heap[0] = queue->heap[queue->count];
	int now = 0, left = 1, right = 2;
	int target = now;
	while (left < queue->count) {
		if (queue->heap[target] < queue->heap[left]) target = left;
		if (queue->heap[target] < queue->heap[right] && right < queue->count) target = right;
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
int comppoint(const void* a, const void* b) {
	point o1 = *(point*)a;
	point o2 = *(point*)b;
	return o1.m - o2.m;
}
int compint(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	point* arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		point p;
		scanf("%d %d", &p.m, &p.v);
		arr[i] = p;
	}
	qsort(arr, n, sizeof(point), comppoint);
	int* c = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
	}
	qsort(c, k, sizeof(int), compint);
	priorityQueue queue;
	initQueue(&queue);
	long long int sum = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && arr[idx].m <= c[i]) {
			push(&queue, arr[idx++].v);
		}
		if (!empty(&queue)) {
			sum += pop(&queue);
		}
	}
	printf("%lld", sum);
}