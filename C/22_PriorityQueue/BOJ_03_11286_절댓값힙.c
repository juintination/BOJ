#include <stdio.h>
#define math_abs(x) x < 0 ? -x : x
#define heap_size 100000
typedef struct {
	int x, abs;
} point;
void swap(point* a, point* b) {
	point temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct priorityQueue {
	point heap[heap_size];
	int count;
} priorityQueue;
void initpQueue(priorityQueue* pqueue) {
	pqueue->count = 0;
}
void push(priorityQueue* pqueue, int x) {
	if (pqueue->count >= heap_size) return;
	pqueue->heap[pqueue->count].x = x;
	pqueue->heap[pqueue->count].abs = math_abs(x);
	int now = pqueue->count;
	int parent = (pqueue->count - 1) / 2;
	while (now > 0 && (pqueue->heap[parent].abs > pqueue->heap[now].abs || (pqueue->heap[parent].abs == pqueue->heap[now].abs && pqueue->heap[parent].x > pqueue->heap[now].x))) {
		swap(&pqueue->heap[now], &pqueue->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pqueue->count++;
}
point pop(priorityQueue* pqueue) {
	point p = pqueue->heap[0];
	pqueue->count--;
	pqueue->heap[0] = pqueue->heap[pqueue->count];
	int now = 0, left = 1, right = 2;
	int target = now;
	while (left < pqueue->count) {
		if (pqueue->heap[target].abs > pqueue->heap[left].abs) target = left;
		if (pqueue->heap[target].abs == pqueue->heap[left].abs && pqueue->heap[target].x > pqueue->heap[left].x) target = left;
		if (pqueue->heap[target].abs > pqueue->heap[right].abs && right < pqueue->count) target = right;
		if (pqueue->heap[target].abs == pqueue->heap[right].abs && pqueue->heap[target].x > pqueue->heap[right].x) target = right;
		if (target == now) break;
		else {
			swap(&pqueue->heap[now], &pqueue->heap[target]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}
	return p;
}
int empty(priorityQueue* pqueue) {
	if (pqueue->count == 0) return 1;
	else return 0;
}
main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	priorityQueue pqueue;
	initpQueue(&pqueue);
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (!empty(&pqueue)) result[cnt++] = pop(&pqueue).x;
			else result[cnt++] = 0;
		}
		else {
			push(&pqueue, x);
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}