#include <stdio.h>
int stack[1000000], cnt[1000001] = { 0 };
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
int pop() {
	return stack[idx--];
}
int size() {
	return idx + 1;
}
int top() {
	return stack[idx];
}
main() {
	int n;
	scanf("%d", &n);
	int* num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		cnt[num[i]]++;
	}
	for (int i = 0; i < n; i++) {
		while (size() > 0 && cnt[num[top()]] < cnt[num[i]]) {
			num[pop()] = num[i];
		}
		push(i);
	}
	while (size() > 0) {
		num[pop()] = -1;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
}