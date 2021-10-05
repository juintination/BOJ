#include <stdio.h>
main() {
	int n;
	scanf("%d", &n);
    int* result = (int*)malloc(sizeof(int) * n);
    int* a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		result[i] = a[i] + b[i];
	}
    for (int i = 0; i < n; i++) {
		printf("Case #%d: %d + %d = %d\n", i + 1, a[i], b[i], result[i]);
	}
}