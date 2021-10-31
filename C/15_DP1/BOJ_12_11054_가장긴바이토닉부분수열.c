#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * n);
	int* dp2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = dp2[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}
	int max = 1;
	for (int i = 0; i < n; i++) {
		max = math_max(max, dp[i] + dp2[i]);
	}
	printf("%d", max - 1);
}