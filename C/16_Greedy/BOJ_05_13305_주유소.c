#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n;
	scanf("%d", &n);
	long long int* arr = (long long int*)malloc(sizeof(long long int) * (n - 1));
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &arr[i]);
	}
	long long int* cost = (long long int*)malloc(sizeof(long long int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &cost[i]);
	}
	long long int min = cost[0], sum = 0;
	for (int i = 0; i < n - 1; i++) {
		min = math_min(min, cost[i]);
		sum += min * arr[i];
	}
	printf("%lld", sum);
}