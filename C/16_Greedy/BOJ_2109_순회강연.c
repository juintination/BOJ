#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
typedef struct {
	int p, d;
} point;
int compare(const void* a, const void* b) {
	point o1 = *(point*)a;
	point o2 = *(point*)b;
	return o2.p - o1.p;
}
main() {
	int n, max;
	scanf("%d", &n);
	point* arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		point p;
		scanf("%d %d", &p.p, &p.d);
		arr[i] = p;
		max = math_max(max, p.d);
	}
	qsort(arr, n, sizeof(point), compare);
	int* visited = (int*)malloc(sizeof(int) * (max + 1));
	for (int i = 0; i <= max; i++) {
		visited[i] = 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		point p = arr[i];
		while (p.d-- > 0) {
			if (!visited[p.d]) {
				visited[p.d] = 1;
				sum += p.p;
				break;
			}
		}
	}
	printf("%d", sum);
}