#include <stdio.h>
#include <stdlib.h>
#define math_min(a, b) a < b ? a : b
int s, result, visited[1001][1001];
typedef struct {
	int screen, clipboard, cnt;
} Emoticon;
typedef struct node {
	Emoticon emoticon;
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
void push(Queue* queue, int x, int y, int z) {
	node* now = (node*)malloc(sizeof(node));
	now->emoticon.screen = x;
	now->emoticon.clipboard = y;
	now->emoticon.cnt = z;
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
Emoticon pop(Queue* queue) {
	Emoticon re;
	node* now;
	now = queue->front;
	re = now->emoticon;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}
int empty(Queue* queue) {
	if (queue->count == 0) return 1;
	else return 0;
}
void bfs() {
	Queue queue;
	initQueue(&queue);
	push(&queue, 1, 0, 0);
	visited[1][0] = 1;
	while (!empty(&queue)) {
		Emoticon e = pop(&queue);
		if (e.screen == s) {
			result = e.cnt;
			return;
		}
		if (!visited[e.screen][e.screen]) { //copy
			push(&queue, e.screen, e.screen, e.cnt + 1);
			visited[e.screen][e.screen] = 1;
		}
		if (e.clipboard != 0 && e.screen + e.clipboard <= 1000 && !visited[e.screen + e.clipboard][e.clipboard]) { //paste
			push(&queue, e.screen + e.clipboard, e.clipboard, e.cnt + 1);
			visited[e.screen + e.clipboard][e.clipboard] = 1;
		}
		if (e.screen > 0 && !visited[e.screen - 1][e.clipboard]) { //delete
			push(&queue, e.screen - 1, e.clipboard, e.cnt + 1);
			visited[e.screen - 1][e.clipboard] = 1;
		}
	}
}
main() {
	scanf("%d", &s);
	bfs();
	printf("%d", result);
}