#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n;
	scanf("%d", &n);
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = i;
		for (int j = 2; j * j <= i; j++) {
			dp[i] = math_min(dp[i], dp[i - j * j] + 1);
		}
	}
	printf("%d", dp[n]);
}