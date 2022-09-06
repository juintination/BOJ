#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int plus1;
int makeZero(int a) {
	int mult2 = 0;
	while (a != 0) {
		if (a % 2 == 0) {
			a /= 2;
			mult2++;
		}
		else {
			a--;
			plus1++;
		}
	}
	return mult2;
}
main() {
	int n, a, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		int mult2 = makeZero(a);
		max = math_max(max, mult2);
	}
	printf("%d", max + plus1);
}