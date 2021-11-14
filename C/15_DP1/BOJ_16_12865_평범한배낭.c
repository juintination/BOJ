#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int dp[101][100001], weight[101], value[101];
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (weight[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = math_max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	printf("%d", dp[n][k]);
}