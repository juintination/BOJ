#include <stdio.h>
main() {
	int n, num;
	int cnt[10001] = { 0 }, sum[10001] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		cnt[num]++;
	}
	sum[0] = cnt[0];
	for (int i = 1; i < 10001; i++) {
		sum[i] = sum[i - 1] + cnt[i];
	}
	for (int j = 1; j <= 10001; j++) {
		if (cnt[j - 1] != 0) {
			if (j != 1) {
				for (int k = 0; k < sum[j - 1] - sum[j - 2]; k++) {
					printf("%d\n", j - 1);
				}
			}
			else {
				for (int k = 0; k < sum[0]; k++) {
					printf("%d\n", 0);
				}
			}
		}
		if (sum[j - 1] == n) break;
	}
}