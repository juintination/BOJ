#include <stdio.h>
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
main() {
	int n, a, b, d, cnt = 0;
	scanf("%d", &n);
	int* result = (int*)malloc(sizeof(int) * n);
	while (n--) {
		scanf("%d %d", &a, &b);
		d = gcd(a, b);
		result[cnt++] = a * b / d;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}