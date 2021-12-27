#include <stdio.h>
main() {
	int m, n, sum = 0, tst = 0, min;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (i % (j + 1) == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			sum += i;
			if (tst == 0) {
				min = i;
			}
			tst = 1;
		}
	}
	if (sum != 0) printf("%d\n%d", sum, min);
	else printf("-1");
}