#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int stackIdx = -1, * stack;
void push(int value) {
	stack[++stackIdx] = value;
}
int is_empty() {
	if (stackIdx < 0) return 1;
	else return 0;
}
int pop() {
	if (is_empty()) return INT_MIN;
	else return stack[stackIdx--];
}
main() {
	int n, top = -1;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int* idxArr = (int*)malloc(sizeof(int) * (n + 1));
	int* list = (int*)malloc(sizeof(int) * (n + 1));
	list[++top] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > list[top]) {
			idxArr[i] = ++top;
			list[top] = arr[i];
		}
		else {
			int left = 1, right = top, idx = 1;
			while (left <= right) {
				int mid = (right + left) / 2;
				if (list[mid] >= arr[i]) {
					idx = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			list[idx] = arr[i];
			idxArr[i] = idx;
		}
	}
	printf("%d\n", top);
	stack = (int*)malloc(sizeof(int) * top);
	while (top > 0) {
		if (idxArr[n] == top) {
			push(arr[n--]);
			top--;
		}
		else n--;
	}
	while (!is_empty()) {
		printf("%d ", pop());
	}
}