#include <stdio.h>
main() {
	int n, a, b;
	scanf("%d", &n);
    int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		result[i] = a + b;
	}
    for (int i = 0; i < n; i++) {
		printf("Case #%d: %d\n", i + 1, result[i]);
	}
}