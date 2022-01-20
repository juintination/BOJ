#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) printf("1");
	else if (n == 2) printf("%d", math_min(4, (m - 1) / 2 + 1));
	else if (m <= 6) printf("%d", math_min(4, m));
	else printf("%d", m - 2);
}