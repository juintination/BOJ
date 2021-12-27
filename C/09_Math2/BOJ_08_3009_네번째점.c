#include <stdio.h>
#define math_max(a, b) a > b ? a: b
main() {
	int cnt_x[1001] = { 0 }, cnt_y[1001] = { 0 }, max = 0, result[2];
	for (int i = 0; i < 3; i++) {
		int x, y, z;
		scanf("%d %d", &x, &y);
		cnt_x[x]++;
		cnt_y[y]++;
		z = math_max(x, y);
		max = math_max(max, z);
	}
	for (int i = 1; i <= max; i++) {
		if (cnt_x[i] == 1) {
			result[0] = i;
		}
		if (cnt_y[i] == 1) {
			result[1] = i;
		}
	}
	printf("%d %d", result[0], result[1]);
}