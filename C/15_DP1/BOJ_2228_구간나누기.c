#include <stdio.h>
#define math_max(a, b) a > b ? a : b
const int INF = -3276800;
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* sum = (int*)malloc(sizeof(int) * (n + 1));
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		int arr;
		scanf("%d", &arr);
		sum[i] = sum[i - 1] + arr;
	}
	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (m + 1));
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		dp[0][i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (k >= 2) {
					dp[i][j] = math_max(dp[i][j], dp[k - 2][j - 1] + (sum[i] - sum[k - 1]));
				}
				else if (j == 1) {
					dp[i][j] = math_max(dp[i][j], sum[i]);
				}
			}
		}
	}
	printf("%d", dp[n][m]);
}