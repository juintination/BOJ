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
	printf("%d", arr[0] * arr[n - 1]);
}