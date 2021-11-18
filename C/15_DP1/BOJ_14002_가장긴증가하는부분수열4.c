#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int stack[1001];
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
int pop() {
	if (idx < 0) return -1;
	else return stack[idx--];
}
int empty() {
	if (idx < 0) return 1;
	else return 0;
}
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = math_max(max, dp[i]);
	}
	printf("%d\n", max);
	while (max > 0) {
		n--;
		if (max == dp[n]) {
			push(arr[n]);
			max--;
		}
	}
	while (!empty()) {
		printf("%d ", pop());
	}
}