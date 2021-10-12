#include <stdio.h>
main() {
	int n, x, y, cnt = 0;
	scanf("%d %d", &n, &x);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &y);
		if (y < x) result[cnt++] = y;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", result[i]);
	}
}