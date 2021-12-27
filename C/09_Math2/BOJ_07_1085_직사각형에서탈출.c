#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int left = math_min(x, w - x);
	int right = math_min(y, h - y);
	printf("%d", math_min(left, right));
}