#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		max = math_max(max, arr[i]);
	}
	int min = 0;
	while (min <= max) {
		int mid = (max + min) / 2;
		long long int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				sum += (arr[i] - mid);
			}
		}
		if (sum < m) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	printf("%d", max);
}