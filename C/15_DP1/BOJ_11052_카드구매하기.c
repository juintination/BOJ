#include <stdio.h>
int math_max(int a, int b) {
	return a > b ? a : b;
}
main() {
	int n;
	scanf("%d", &n);
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = math_max(dp[i], dp[i - j] + dp[j]);
		}
	}
	printf("%d", dp[n]);
}