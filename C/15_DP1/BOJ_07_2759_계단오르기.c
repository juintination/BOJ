#include <stdio.h>
int dp[301], arr[301];
int math_max(int a, int b) {
	return a > b ? a : b;
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = math_max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}
	printf("%d", dp[n]);
}