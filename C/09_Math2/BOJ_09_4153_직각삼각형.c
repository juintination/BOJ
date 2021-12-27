#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	while (1) {
		int n[3], max = 0, sum = 0;
		scanf("%d %d %d", &n[0], &n[1], &n[2]);
		if (n[0] == 0 && n[1] == 0 && n[2] == 0) break;
		for (int i = 0; i < 3; i++) {
			max = math_max(max, n[i]);
		}
		for (int i = 0; i < 3; i++) {
			if (n[i] != max) {
				sum += n[i] * n[i];
			}
		}
		if (sum == max * max) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
}