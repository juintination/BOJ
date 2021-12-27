#include <stdio.h>
#include <math.h>
main() {
	int t, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (d == 0) {
			if (r1 == r2) {
				result[cnt++] = -1;
			}
			else {
				result[cnt++] = 0;
			}
		}
		else if (d == r1 + r2 || d == abs(r1 - r2)) {
			result[cnt++] = 1;
		}
		else if (d < r1 + r2 && d > abs(r1 - r2)) {
			result[cnt++] = 2;
		}
		else {
			result[cnt++] = 0;
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}