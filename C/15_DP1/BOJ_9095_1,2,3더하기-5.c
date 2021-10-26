#include <stdio.h>
long long int dp[100001][4];
main() {
	int t, n, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][3] + dp[i - 2][1]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		result[cnt++] = (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}