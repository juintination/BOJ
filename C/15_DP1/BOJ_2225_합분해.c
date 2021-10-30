#include <stdio.h>
long long int dp[201][201];
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 0; i <= k; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	printf("%lld", dp[n][k]);
}