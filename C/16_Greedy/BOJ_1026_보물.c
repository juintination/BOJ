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
	int* a = (int*)malloc(sizeof(int) * n);
	int* b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	qsort(a, n, sizeof(int), compare);
	qsort(b, n, sizeof(int), compare);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n - 1 - i];
	}
	printf("%d", sum);
}