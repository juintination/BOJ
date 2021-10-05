#include <stdio.h>
main() {
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF) {
		printf("%d\n", x + y);
	}
}