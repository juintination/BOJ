#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int dp[1000][3];
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] += math_min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += math_min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += math_min(dp[i - 1][0], dp[i - 1][1]);
	}
	int result = dp[n - 1][0];
	for (int i = 1; i <= 2; i++) {
		result = math_min(result, dp[n - 1][i]);
	}
	printf("%d\n", result);
}