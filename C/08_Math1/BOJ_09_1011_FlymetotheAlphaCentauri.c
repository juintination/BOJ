#include <stdio.h>
#include <math.h>
main() {
	int t, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int d = y - x, max = sqrt(d);
		if (max == sqrt(d)) {
			result[cnt++] = 2 * max - 1;
		}
		else if (d <= pow(max, 2) + max) {
			result[cnt++] = 2 * max;
		}
		else {
			result[cnt++] = 2 * max + 1;
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}