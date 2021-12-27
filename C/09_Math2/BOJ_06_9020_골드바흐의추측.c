#include <stdio.h>
int boolean[10001];
main() {
	int t;
	scanf("%d", &t);
	boolean[1] = 1;
	for (int i = 2; i <= 100; i++) {
		if (boolean[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			boolean[j] = 1;
		}
	}
	while (t--) {
		int n, i, j;
		scanf("%d", &n);
		i = j = n / 2;
		while (1) {
			if (!boolean[i] && !boolean[j]) {
				printf("%d %d\n", i, j);
				break;
			}
			i--;
			j++;
		}
	}
}