#include <stdio.h>
int dp[1000001] = { 0 };
int math_min(int a, int b) {
	return a < b ? a : b;
}
int recur(int n) {
	if (dp[n] == 0) {
		if (n % 6 == 0) {
			dp[n] = math_min(recur(n / 3), recur(n / 2)) + 1;
		}
		else if (n % 3 == 0) {
			dp[n] = math_min(recur(n / 3), recur(n - 1)) + 1;
		}
		else if (n % 2 == 0) {
			dp[n] = math_min(recur(n / 2), recur(n - 1)) + 1;
		}
		else {
			dp[n] = recur(n - 1) + 1;
		}
	}
	else return dp[n];
}
main() {
	int n;
	scanf("%d", &n);
	dp[0] = -1;
	printf("%d", recur(n));
}