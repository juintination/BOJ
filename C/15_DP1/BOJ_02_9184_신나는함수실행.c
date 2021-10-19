#include <stdio.h>
int dp[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return dp[20][20][20];
	}
	else if (a < b && b < c) {
		return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
	}
	else return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
}
main() {
	int a, b, c;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				dp[i][j][k] = w(i, j, k);
			}
		}
	}
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}