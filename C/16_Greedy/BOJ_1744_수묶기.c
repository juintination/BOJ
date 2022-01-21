#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	int left = 0, right = n - 1, sum = 0;
	while (left < n - 1) {
		if (arr[left] < 1 && arr[left + 1] < 1) {
			sum += arr[left] * arr[left + 1];
		}
		else {
			break;
		}
		left += 2;
	}
	while (right > 0) {
		if (arr[right] > 1 && arr[right - 1] > 1) {
			sum += arr[right] * arr[right - 1];
		}
		else {
			break;
		}
		right -= 2;
	}
	for (int i = left; i <= right; i++) {
		sum += arr[i];
	}
	printf("%d", sum);
}