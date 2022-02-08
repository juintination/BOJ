#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	int max = arr[n - 1] - arr[0], min = 0;
	while (min <= max) {
		int mid = (max + min) / 2;
		int cnt = 1, start = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] - start >= mid) {
				cnt++;
				start = arr[i];
			}
		}
		if (cnt < m) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	printf("%d", max);
}