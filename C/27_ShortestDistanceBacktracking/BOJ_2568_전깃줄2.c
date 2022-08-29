#include <stdio.h>
#include <stdlib.h>
int arr[500001], stackIdx = -1, * stack;
void push(int value) {
	stack[++stackIdx] = value;
}
int is_empty() {
	if (stackIdx < 0) return 1;
	else return 0;
}
int pop() {
	if (is_empty()) return -1;
	else return stack[stackIdx--];
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
main() {
	int n, top = -1;
	scanf("%d", &n);
	int* poleA = (int*)malloc(sizeof(int) * (n + 1));
	int* idxArr = (int*)malloc(sizeof(int) * (n + 1));
	int* list = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &poleA[i]);
		scanf("%d", &arr[poleA[i]]);
	}
	qsort(poleA, n + 1, sizeof(int), compare);
	list[++top] = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[poleA[i]] > list[top]) {
			idxArr[i] = ++top;
			list[top] = arr[poleA[i]];
		}
		else {
			int left = 1, right = top, idx = 1;
			while (left <= right) {
				int mid = (right + left) / 2;
				if (list[mid] >= arr[poleA[i]]) {
					idx = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			list[idx] = arr[poleA[i]];
			idxArr[i] = idx;
		}
	}
	printf("%d\n", n - top);
	stack = (int*)malloc(sizeof(int) * (n - top));
	for (int i = n; i > 0; i--) {
		if (idxArr[i] == top) top--;
		else push(poleA[i]);
	}
	while (!is_empty()) {
		printf("%d\n", pop());
	}
}