#include <stdio.h>
#include <stdlib.h>
int move = 0;

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} node;

typedef struct {
	node* front;
	node* rear;
	int count;
} Deque;

void initDeque(Deque* deque) {
	deque->front = deque->rear = NULL;
	deque->count = 0;
}

int empty(Deque* deque) {
	if (deque->count == 0) return 1;
	else return 0;
}

void push_front(Deque* deque, int data) {
	node* now = (node*)malloc(sizeof(node));
	if (empty(deque)) {
		deque->front = now;
		deque->rear = now;
		now->next = NULL;
	}
	else {
		deque->front->prev = now;
		now->next = deque->front;
		deque->front = now;
	}
	now->prev = NULL;
	now->data = data;
	(deque->count)++;
}

void push_back(Deque* deque, int data) {
	node* now = (node*)malloc(sizeof(node));
	if (empty(deque)) {
		deque->front = now;
		deque->rear = now;
		now->prev = NULL;
	}
	else {
		now->prev = deque->rear;
		deque->rear->next = now;
		deque->rear = now;
	}
	now->next = NULL;
	now->data = data;
	(deque->count)++;
}

int pop_front(Deque* deque) {
	if (empty(deque)) return -1;
	else {
		int rdata;
		node* rnode;
		rdata = deque->front->data;
		rnode = deque->front;
		deque->front = deque->front->next;
		if (deque->count == 1) deque->rear = NULL;
		free(rnode);
		(deque->count)--;
		return rdata;
	}
}

int pop_back(Deque* deque) {
	if (empty(deque)) return -1;
	else {
		int rdata;
		node* rnode;
		rdata = deque->rear->data;
		rnode = deque->rear;
		deque->rear = deque->rear->prev;
		if (deque->count == 1) deque->rear = NULL;
		free(rnode);
		(deque->count)--;
		return rdata;
	}
}

int moving(Deque* deque, int num) {
	int rightcnt = 0, leftcnt = 0;
	node* tmp = deque->front;
	for (int i = 0; i < deque->count; i++) {
		if (num == deque->front->data) break;
		deque->front = deque->front->next;
		rightcnt++;
	}
	deque->front = tmp;
	leftcnt = deque->count - rightcnt;
	if (rightcnt > leftcnt) return -leftcnt;
	else return rightcnt;
}

void rotate(Deque* deque, int movecnt) {
	if (movecnt < 0) {
		for (int i = 0; i < -movecnt; i++) {
			int data = pop_back(deque);
			push_front(deque, data);
			move++;
		}
	}
	else if (movecnt == 0) return;
	else {
		for (int i = 0; i < movecnt; i++) {
			int data = pop_front(deque);
			push_back(deque, data);
			move++;
		}
	}
}

main() {
	int n, m;
	Deque deque;
	initDeque(&deque);
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		push_back(&deque, i);
	}
	for (int i = 0; i < m; i++) {
		rotate(&deque, moving(&deque, arr[i]));
		pop_front(&deque);
	}
	printf("%d\n", move);
}