#include <stdio.h>
int dp[501][501] = { 0 }, arr[501][501];
int math_max(int a, int b) {
	return a > b ? a : b;
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = math_max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = math_max(result, dp[n][i]);
	}
	printf("%d", result);
}