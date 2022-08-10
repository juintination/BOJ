#include <stdio.h>
#include <stdlib.h>
main() {
	int n;
	scanf("%d", &n);
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	int* parent = (int*)malloc(sizeof(int) * (n + 1));
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		parent[i] = i - 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			parent[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			parent[i] = i / 2;
		}
	}
	printf("%d\n", dp[n]);
	int idx = n;
	for (int i = 0; i < dp[n]; i++) {
		printf("%d ", idx);
		idx = parent[idx];
	}
	printf("1");
}