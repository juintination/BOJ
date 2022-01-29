#include <stdio.h>
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (k + 1));
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 0;
		}
		dp[i][0] = 1;
	}
	for (int i = 0; i <= k; i++) {
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	printf("%d", dp[n][k]);
}