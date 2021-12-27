#include <stdio.h>
main() {
	int n, cnt = 1, range = 2;
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
	}
	else {
		while (range <= n) {
			range += 6 * cnt;
			cnt++;
		}
		printf("%d", cnt);
	}
}