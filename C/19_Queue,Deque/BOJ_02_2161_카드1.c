#include <stdio.h>
int queue[1000];
int front = 0, rear = -1;
void push(int x) {
	queue[++rear] = x;
}

main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		push(i + 1);
	}
	if (n != 1) {
		while (1) {
			printf("%d ", queue[front]);
			front = (front + 1) % n;
			if (rear == front) {
				printf("%d ", queue[front]);
				break;
			}
			rear = (rear + 1) % n;
			queue[rear] = queue[front];
			front = (front + 1) % n;
			if (rear == front) {
				printf("%d ", queue[front]);
				break;
			}
		}
	}
	else printf("1");
}