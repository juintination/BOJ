#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n, arr[15][15], dp[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < n; i++) {
		if (i + arr[i][0] <= n) {
			dp[i + arr[i][0]] = math_max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
		}
		dp[i + 1] = math_max(dp[i + 1], dp[i]);
	}
	printf("%d", dp[n]);
}