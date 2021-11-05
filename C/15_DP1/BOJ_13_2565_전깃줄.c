#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int arr[501] = { 0 }, dp[501];
main() {
	int n, tmp, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		max = math_max(max, tmp);
		dp[tmp] = 1;
		scanf("%d", &arr[tmp]);
	}
	for (int i = 1; i <= max; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		}
	}
	int result = 0;
	for (int i = 1; i <= max; i++) {
		result = math_max(result, dp[i]);
	}
	printf("%d", n - result);
}