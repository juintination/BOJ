#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
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
	int max = 0;
	for (int i = n - 1; i >= 0; i--) {
		arr[i] *= (n - i);
		max = math_max(max, arr[i]);
	}
	printf("%d", max);
}