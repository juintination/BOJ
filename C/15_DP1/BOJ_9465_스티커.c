#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int arr[10001][2], dp[10001][2];
main() {
	int t, n, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[j][i]);
			}
		}
		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = math_max(dp[i - 1][1] + arr[i][0], dp[i - 2][1] + arr[i][0]);
			dp[i][1] = math_max(dp[i - 1][0] + arr[i][1], dp[i - 2][0] + arr[i][1]);
		}
		result[cnt++] = math_max(dp[n][0], dp[n][1]);
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}