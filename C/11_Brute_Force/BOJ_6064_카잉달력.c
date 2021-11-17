#include <stdio.h>
main() {
	int t, m, n, x, y, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int tmp = 0;
		y %= n;
		while (1) {
			int year = m * tmp + x;
			if (year % n == y) {
				result[cnt++] = year;
				break;
			}
			if (year > m* n) {
				result[cnt++] = -1;
				break;
			}
			tmp++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}