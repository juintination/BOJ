#include <stdio.h>
main() {
	int n, cnt = 1, sum = 0;
	scanf("%d", &n);
	while (1) {
		sum += cnt;
		if (n <= sum) {
			if (cnt % 2 == 1) {
				printf("%d/%d", sum - n + 1, cnt + n - sum);
			}
			else {
				printf("%d/%d", cnt + n - sum, sum - n + 1);
			}
			break;
		}
		cnt++;
	}
}