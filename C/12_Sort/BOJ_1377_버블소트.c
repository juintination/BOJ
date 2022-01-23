#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
typedef struct {
	int num, idx;
} point;
int compare(const void* a, const void* b) {
	point o1 = *(point*)a;
	point o2 = *(point*)b;
	return o1.num - o2.num;
}
main() {
	int n;
	scanf("%d", &n);
	point* arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].num);
		arr[i].idx = i;
	}
	qsort(arr, n, sizeof(point), compare);
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = math_max(max, arr[i].idx - i + 1);
	}
	printf("%d", max);
}