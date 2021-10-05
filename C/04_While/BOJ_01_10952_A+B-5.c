#include <stdio.h>
main() {
	while (1) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		if (x == 0 && y == 0) break;
		printf("%d\n", x + y);
	}
}