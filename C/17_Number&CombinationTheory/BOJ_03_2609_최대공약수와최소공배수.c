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
	int a, b, d;
	scanf("%d %d", &a, &b);
	d = gcd(a, b);
	printf("%d\n%d", d, a * b / d);
}