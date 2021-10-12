#include <stdio.h>
int queue[10000];
int f = 0, r = 0;
void push(int x) {
	queue[r++] = x;
}
int pop() {
	if (r == f) return -1;
	else return queue[f++];
}
int size() {
	return (r - f);
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
int front() {
	if (r == f) return -1;
	else return queue[f];
}
int back() {
	if (r == f) return -1;
	else return queue[r - 1];
}

main() {
	int n, cnt = 0;
	char order[6];
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &order);
		if (order[0] == 'p') {
			if (order[1] == 'u') {
				int x;
				scanf("%d", &x);
				push(x);
			}
			else result[cnt++] = pop();
		}
		else if (order[0] == 's') {
			result[cnt++] = size();
		}
		else if (order[0] == 'e') {
			result[cnt++] = empty();
		}
		else if (order[0] == 'f') {
			result[cnt++] = front();
		}
		else if (order[0] == 'b') {
			result[cnt++] = back();
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}