#include <stdio.h>
#include <math.h>
int boolean[1000001];
main() {
	int m, n, tst = 0;
	scanf("%d %d", &m, &n);
	boolean[1] = 1;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (boolean[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			boolean[j] = 1;
		}
	}
	for (int i = m; i <= n; i++) {
		if (!boolean[i]) printf("%d\n", i);
	}
}