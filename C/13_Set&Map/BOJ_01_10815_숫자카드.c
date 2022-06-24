#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n, m;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
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
		printf("%d ", bsearch(&target[i], arr, n, sizeof(int), compare) > 0 ? 1 : 0);
	}
}