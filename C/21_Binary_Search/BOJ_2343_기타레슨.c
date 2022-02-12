#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	int max = 0, min = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		min = math_max(min, arr[i]);
		max += arr[i];
	}
	int result = max;
	while (min <= max) {
		int mid = (max + min) / 2;
		int sum = 0, cnt = 1;
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] <= mid) {
				sum += arr[i];
			}
			else {
				sum = arr[i];
				cnt++;
			}
		}
		if (cnt <= m) {
			result = mid;
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	printf("%d", result);
}