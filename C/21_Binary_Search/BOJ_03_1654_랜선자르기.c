#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int k, n;
	scanf("%d %d", &k, &n);
	int* arr = (int*)malloc(sizeof(int) * k);
	long long int max = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
		max = math_max(max, arr[i]);
	}
	long long int min = 1;
	while (min <= max) {
		long long int mid = (max + min) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (arr[i] / mid);
		}
		if (cnt < n) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	printf("%d", max);
}