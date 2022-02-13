#include <stdio.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	int high = 0, low = 2147483647;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		high = math_max(high, arr[i]);
		low = math_min(low, arr[i]);
	}
	int left = 0, right = high - low, result = right;
	while (left <= right) {
		int mid = (right + left) / 2;
		int max = arr[0], min = arr[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			max = math_max(max, arr[i]);
			min = math_min(min, arr[i]);
			if (max - min > mid) {
				max = min = arr[i];
				cnt++;
			}
		}
		if (cnt <= m) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d", result);
}