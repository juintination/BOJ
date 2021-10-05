#include <stdio.h>
main() {
	int n, cnt[10] = { 0 };
	scanf("%d", &n);
	while (1) {
		cnt[n % 10]++;
		n = n / 10;
		if (n == 0) break;
	}
	for (int i = 10; i > 0; i--) {
		if (cnt[i - 1] != 0) {
			for (int j = 0; j < cnt[i - 1]; j++) {
				printf("%d", i - 1);
			}
		}
	}
}