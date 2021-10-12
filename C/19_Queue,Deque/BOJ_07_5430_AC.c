#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} node;

typedef struct {
	node* front;
	node* rear;
	int count;
	int move;
} Deque;

void initDeque(Deque* deque) {
	deque->front = deque->rear = NULL;
	deque->count = 0;
	deque->move = 0;
}

int empty(Deque* deque) {
	if (deque->count == 0) return 1;
	else return 0;
}

void push(Deque* deque, int data) {
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

main() {
	int t, n, x;
	char p[100000], c;
	Deque deque;
	scanf("%d", &t);
	while (t--) {
		initDeque(&deque);
		int swap = 0, tst = 0;
		scanf("%s", p);
		getchar();
		scanf("%d", &n);
		getchar();
		if (n != 0) {
			scanf("%c", &c);
			for (int i = 0; i < n; i++) {
				scanf("%d", &x);
				getchar();
				push(&deque, x);
			}
		}
		else scanf("%c %c", &c, &c);
		getchar();
		for (int i = 0; i < strlen(p); i++) {
			if (p[i] == 'R') {
				swap = !swap;
			}
			else if (p[i] == 'D') {
				if (empty(&deque)) {
					printf("error\n");
					tst++;
					break;
				}
				else if (swap == 0) {
					pop_front(&deque);
				}
				else pop_back(&deque);
			}
		}
		if (tst == 0) {
			printf("[");
			while (!empty(&deque)) {
				if (swap == 0) {
					printf("%d", pop_front(&deque));
				}
				else {
					printf("%d", pop_back(&deque));
				}
				if (deque.count > 0) {
					printf(",");
				}
			}
			printf("]\n");
		}
	}
}