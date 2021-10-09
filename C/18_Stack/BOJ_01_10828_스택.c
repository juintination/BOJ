#include <stdio.h>
#include <stdlib.h>
int stack[10000];
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
int pop() {
	if (idx < 0) return -1;
	else return stack[idx--];
}
int size() {
	return idx + 1;
}
int empty() {
	if (idx < 0) return 1;
	else return 0;
}
int top() {
	if (idx == -1) {
		return -1;
	}
	else {
		return stack[idx];
	}
}
main() {
	int n, x;
	int cnt = 0;
	char arr[6];
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		if (arr[0] == 'p') {
			if (arr[1] == 'o') result[cnt++] = pop();
			else {
				scanf("%d", &x);
				push(x);
			}
		}
		else if (arr[0] == 't') result[cnt++] = top();
		else if (arr[0] == 'e') result[cnt++] = empty();
		else result[cnt++] = size();
	}
	for (int i = 0; i < cnt; i++) printf("%d\n", result[i]);
	free(result);
}