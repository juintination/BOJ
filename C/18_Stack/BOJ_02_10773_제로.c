#include <stdio.h>
#include <stdlib.h>
int idx = -1, sum = 0;
void push(int* stack, int value) {
	stack[++idx] = value;
}
void erase(int* stack) {
	sum -= stack[--idx];
	idx--;
}
void plus(int* stack) {
	sum += stack[idx];
}
main() {
	int n, num;
	int cnt = 0;
	scanf("%d", &n);
	int* stack = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		push(stack, num);
		if (num == 0) {
			erase(stack);
		}
		else {
			plus(stack);
		}
	}
	printf("%d", sum);
	free(stack);
}