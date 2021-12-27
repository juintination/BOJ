#include <stdio.h>
#include <math.h>
int boolean[246913];
main() {
	boolean[1] = 1;
	for (int i = 2; i <= (int)sqrt(246912); i++) {
		if (boolean[i]) continue;
		for (int j = i * i; j <= 246912; j += i) {
			boolean[j] = 1;
		}
	}
	while (1) {
		int n, cnt;
		scanf("%d", &n);
		if (n == 0) break;
		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!boolean[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
}