#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		if (n >= 2 * m) {
			n--;
		}
		else {
			m--;
		}
	}
	printf("%d", math_min(n / 2, m));
}