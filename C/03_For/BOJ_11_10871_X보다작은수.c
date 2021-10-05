#include <stdio.h>
main() {
	int n, x, y;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &y);
		if (y < x) {
			printf("%d\n", y);
		}
	}
}