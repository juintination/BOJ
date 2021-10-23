#include <stdio.h>
int cost[1000][3], dp[1000][3];
int math_min(int a, int b) {
	return a < b ? a : b;
}
int paint(int n, int color) {
	if (dp[n][color] == 0) {
		if (color == 0) {
			dp[n][0] = math_min(paint(n - 1, 2), paint(n - 1, 1)) + cost[n][0];
		}
		else if (color == 1) {
			dp[n][1] = math_min(paint(n - 1, 2), paint(n - 1, 0)) + cost[n][1];
		}
		else {
			dp[n][2] = math_min(paint(n - 1, 1), paint(n - 1, 0)) + cost[n][2];
		}
	}
	return dp[n][color];
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
	int result = math_min(paint(n - 1, 0), math_min(paint(n - 1, 1), paint(n - 1, 2)));
	printf("%d", result);
}