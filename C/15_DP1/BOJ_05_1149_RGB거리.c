#include <stdio.h>
int cost[1000][3], dp[1000][3];
int paint(int n, int color) {
	if (dp[n][color] == 0) {
		if (color == 0) {
			int min;
			if (paint(n - 1, 1) > paint(n - 1, 2)) {
				min = paint(n - 1, 2);
			}
			else min = paint(n - 1, 1);
			dp[n][0] = min + cost[n][0];
		}
		else if (color == 1) {
			int min;
			if (paint(n - 1, 0) > paint(n - 1, 2)) {
				min = paint(n - 1, 2);
			}
			else min = paint(n - 1, 0);
			dp[n][1] = min + cost[n][1];
		}
		else {
			int min;
			if (paint(n - 1, 0) > paint(n - 1, 1)) {
				min = paint(n - 1, 1);
			}
			else min = paint(n - 1, 0);
			dp[n][2] = min + cost[n][2];
		}
	}
	return dp[n][color];
}
main() {
	int n, min;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
	if (paint(n - 1, 0) > paint(n - 1, 1)) {
		min = paint(n - 1, 1);
	}
	else min = paint(n - 1, 0);
	if (min > paint(n - 1, 2)) {
		min = paint(n - 1, 2);
	}
	printf("%d", min);
}