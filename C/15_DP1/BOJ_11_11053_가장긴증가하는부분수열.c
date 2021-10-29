#include <stdio.h>
int math_max(int a, int b) {
	return a > b ? a : b;
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
	printf("%d", max);
}