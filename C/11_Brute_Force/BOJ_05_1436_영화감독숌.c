#include <stdio.h>
main() {
	int n, cnt = 0, num = 666, checknum, result;
	scanf("%d", &n);
	getchar();
	while (1) {
		checknum = num;
		while (1) {
			if (checknum % 1000 == 666) {
				result = num;
				cnt++;
				break;
			}
			else checknum = checknum / 10;
			if (checknum < 10) break;
		}
		if (cnt == n) break;
		num++;
	}
	printf("%d\n", result);
}