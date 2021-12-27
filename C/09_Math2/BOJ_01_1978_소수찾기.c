#include <stdio.h>
main() {
	int n, tmp, sum = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);
		int cnt = 0;
		for (int i = 0; i < tmp; i++) {
			if (tmp % (i + 1) == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			sum++;
		}
	}
	printf("%d", sum);
}