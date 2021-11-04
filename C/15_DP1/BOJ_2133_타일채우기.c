#include <stdio.h>
main() {
	int n;
	scanf("%d", &n);
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	if (n % 2 == 0) printf("%d", dp[n]);
	else printf("0");
}