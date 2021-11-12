#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	int max = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = math_max(dp[i - 1] + arr[i], arr[i]);
		max = math_max(max, dp[i]);
	}
	printf("%d", max);
}