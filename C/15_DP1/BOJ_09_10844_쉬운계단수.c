#include <stdio.h>
main() {
	int n;
	int dp[101][10];
	scanf("%d", &n);
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][1] % 1000000000;
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8] % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + dp[n][i]) % 1000000000;
	}
	printf("%d", result % 1000000000);
}