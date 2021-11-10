#include <stdio.h>
//#define math_min(a, b) a < b ? a : b
int dp[1000][3], cost[1000][3];
int math_min(int a, int b) {
	return a < b ? a : b;
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	int result = 2147483647;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				dp[0][j] = cost[0][i];
			}
			else {
				dp[0][j] = 1000 * 1000 + 1;
			}
		}
		for (int j = 1; j < n; j++) {
			dp[j][0] = math_min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = math_min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = math_min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
		}
		for (int j = 0; j < 3; j++) {
			if (j != i) {
				result = math_min(result, dp[n - 1][j]);
			}
		}
	}
	printf("%d\n", result);
}