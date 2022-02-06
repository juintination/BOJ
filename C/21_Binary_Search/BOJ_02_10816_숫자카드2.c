#include <stdio.h>
#include <stdlib.h>
int n, m, *arr;
int lowerBound(int key) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key <= arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}
int upperBound(int key) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key >= arr[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high;
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
	int* result = (int*)malloc(sizeof(int) * m);
	int cnt = 0, key;
	for (int i = 0; i < m; i++) {
		scanf("%d", &key);
		result[cnt++] = upperBound(key) + 1 - lowerBound(key);
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", result[i]);
	}
}