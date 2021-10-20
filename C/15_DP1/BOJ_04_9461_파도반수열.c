#include <stdio.h>
long long int dp[101];
long long int wave(int n) {
	if (dp[n] == -1) {
		dp[n] = wave(n - 2) + wave(n - 3);
	}
	return dp[n];
}
main() {
	int t;
	scanf("%d", &t);
	int* n = (int*)malloc(sizeof(int) * t);
	for (int i = 0; i <= 100; i++) {
		dp[i] = -1;
	}
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < t; i++) {
		printf("%lld\n", wave(n[i]));
	}
}