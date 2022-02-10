#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, m, start, end, *visited;
typedef struct {
	int x, cost;
} Point;
typedef struct Node {
	Point point;
	struct Node* next;
} Node;
void add(Node* target, int x, int cost) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->point.x = x;
	now->point.cost = cost;
	now->next = target->next;
	target->next = now;
	return;
}
Node** list;
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
int bfs(int mid) {
	Queue queue;
	initQueue(&queue);
	push(&queue, start);
	visited[start] = 1;
	while (!empty(&queue)) {
		int tmp = pop(&queue);
		if (tmp == end) return 1;
		Node* curr = list[tmp]->next;
		while (curr != NULL) {
			Point p = curr->point;
			if (!visited[p.x] && mid <= p.cost) {
				push(&queue, p.x);
				visited[p.x] = 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}
main() {
	scanf("%d %d", &n, &m);
	list = (Node**)malloc(sizeof(Node*) * (n + 1));
	visited = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		list[i] = (Node*)malloc(sizeof(Node));
		list[i]->next = NULL;
	}
	int max = 0, min = 2147483647;
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		max = math_max(max, c);
		min = math_min(min, c);
		add(list[a], b, c);
		add(list[b], a, c);
	}
	scanf("%d %d", &start, &end);
	int result = 0;
	while (min <= max) {
		int mid = (max + min) / 2;
		memset(visited, 0, sizeof(int) * (n + 1));
		if (bfs(mid)) {
			result = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	printf("%d", result);
}