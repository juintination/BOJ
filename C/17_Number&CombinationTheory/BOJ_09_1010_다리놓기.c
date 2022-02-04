#include <stdio.h>
int dp[30][30];
main() {
	int t, n, m, cnt = 0;
	for (int i = 0; i < 30; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < 30; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		scanf("%d %d", &n, &m);
		result[cnt++] = dp[m][n];
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}