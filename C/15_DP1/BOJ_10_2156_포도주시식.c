#include <stdio.h>
int math_max(int a, int b) {
	return a > b ? a : b;
}
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * (n + 2));
	int* dp = (int*)malloc(sizeof(int) * (n + 2));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = math_max(dp[i - 1], math_max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
	}
	printf("%d", dp[n]);
}