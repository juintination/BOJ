#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x, y;
} point;
int compare(const void* a, const void* b) {
	point o1 = *(point*)a;
	point o2 = *(point*)b;
	if (o1.x == o2.x) return o1.y - o2.y;
	else return o1.x - o2.x;
}
main() {
	int n;
	scanf("%d", &n);
	point* arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(point), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}