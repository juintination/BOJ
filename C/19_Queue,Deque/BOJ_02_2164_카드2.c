#include <stdio.h>
int queue[500000];
int front = 0, rear = -1;
void push(int x) {
	queue[++rear] = x;
}

main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		push(i + 1);
	}
	while (1) {
		front = (front + 1) % n;
		if (rear == front) break;
		rear = (rear + 1) % n;
		queue[rear] = queue[front];
		front = (front + 1) % n;
		if (rear == front) break;
	}
	printf("%d", queue[rear]);
}