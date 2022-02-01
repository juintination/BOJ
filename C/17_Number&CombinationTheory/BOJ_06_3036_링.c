#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n, first, other, cnt = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * (n - 1));
	int* b = (int*)malloc(sizeof(int) * (n - 1));
	scanf("%d", &first);
	for (int i = 1; i < n; i++) {
		scanf("%d", &other);
		int d = gcd(first, other);
		a[cnt] = first / d;
		b[cnt++] = other / d;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d/%d\n", a[i], b[i]);
	}
}