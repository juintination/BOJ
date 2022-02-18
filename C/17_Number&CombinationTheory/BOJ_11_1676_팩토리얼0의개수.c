#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, two = 0, five = 0;
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		int tmp = i;
		while (1) {
			if (tmp % 2 != 0 && tmp % 5 != 0) break;
			if (tmp % 2 == 0) {
				tmp /= 2;
				two++;
			}
			if (tmp % 5 == 0) {
				tmp /= 5;
				five++;
			}
		}
	}
	printf("%d", math_min(two, five));
}