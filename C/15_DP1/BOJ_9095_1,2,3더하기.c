#include <stdio.h>
int plus(int n) {
	int f1 = 0;
	int f2 = 1;
	int f3 = 1;
	int result = 1;
	for (int i = 1; i < n; i++) {
		result = f1 + f2 + f3;
		f1 = f2;
		f2 = f3;
		f3 = result;
	}
	return result;
}
main() {
	int n;
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &result[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", plus(result[i]));
	}
}