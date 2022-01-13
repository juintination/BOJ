#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long int s, t, set[1000];
typedef struct {
	long long int s;
	char str[50];
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
void push(Queue* queue, long long int s, char tmp[]) {
	node* now = (node*)malloc(sizeof(node));
	now->point.s = s;
	strcpy(now->point.str, tmp);
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
int cnt = 0;
int contains(long long int x) {
	for (int i = 0; i < cnt; i++) {
		if (set[i] == x) {
			return 1;
		}
	}
	return 0;
}
void bfs() {
	char tmp[50] = "";
	Queue queue;
	initQueue(&queue);
	push(&queue, s, tmp);
	while (!empty(&queue)) {
		Point p = pop(&queue);
		if (p.s == t) {
			printf("%s", p.str);
			exit(0);
		}
		if (p.s <= sqrt(t) && !contains(p.s * p.s)) {
			set[cnt++] = p.s * p.s;
			strcpy(tmp, p.str);
			strcat(tmp, "*");
			push(&queue, p.s * p.s, tmp);
		}
		if (p.s <= t / 2 && !contains(p.s + p.s)) {
			set[cnt++] = p.s + p.s;
			strcpy(tmp, p.str);
			strcat(tmp, "+");
			push(&queue, p.s + p.s, tmp);
		}
		if (p.s > t && !contains(0)) {
			set[cnt++] = 0;
			strcpy(tmp, p.str);
			strcat(tmp, "-");
			push(&queue, 0, tmp);
		}
		if (p.s != 0 && !contains(1)) {
			set[cnt++] = 1;
			strcpy(tmp, p.str);
			strcat(tmp, "/");
			push(&queue, 1, tmp);
		}
	}
}
main() {
	scanf("%lld %lld", &s, &t);
	if (s == t) {
		printf("0");
		exit(0);
	}
	else bfs();
	printf("-1");
}