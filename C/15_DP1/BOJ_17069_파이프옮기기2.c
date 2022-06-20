#include <stdio.h>
const int horizontal = 0, vertical = 1, diagonal = 2;
main() {
	int n;
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * n);
	long long int*** dp = (long long int***)malloc(sizeof(int**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		dp[i] = (long long int**)malloc(sizeof(long long int*) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = (long long int*)malloc(sizeof(int) * 3);
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (j + 1 < n && arr[i][j + 1] != 1) {
				dp[i][j + 1][0] += (dp[i][j][0] + dp[i][j][2]);
			}
			if (i + 1 < n && arr[i + 1][j] != 1) {
				dp[i + 1][j][1] += (dp[i][j][1] + dp[i][j][2]);
			}
			if (i + 1 < n && j + 1 < n && arr[i + 1][j] != 1 && arr[i][j + 1] != 1 && arr[i + 1][j + 1] != 1) {
				dp[i + 1][j + 1][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]);
			}
		}
	}
	printf("%lld", dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);
}