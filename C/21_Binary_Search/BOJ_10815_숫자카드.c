#include <stdio.h>
#include <stdlib.h>
int n, m, *arr;
int binarySearch(int target) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > target) {
			high = mid - 1;
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &m);
	int* target = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &target[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", binarySearch(target[i]));
	}
}