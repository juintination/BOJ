#include <stdio.h>
main() {
	int n, test[1000], cnt[1000] = { 0 }, t = 0;
	scanf("%d", &n);
	for (int l = 0; l < n; l++) {
		scanf("%d", &test[l]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (test[i] > test[j]) {
				cnt[i]++;
			}
		}
	}
	while (1) {
		for (int k = 0; k < n; k++) {
			if (cnt[k] == t) {
				printf("%d\n", test[k]);
				t++;
				break;
			}
		}
		if (t == n) break;
	}
}