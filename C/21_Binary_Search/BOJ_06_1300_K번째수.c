#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long int min = 1, max = k, result = 0;
	while (min <= max) {
		long long int mid = (max + min) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += math_min(mid / i, n);
		}
		if (cnt >= k) {
			result = mid;
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	printf("%lld", result);
}