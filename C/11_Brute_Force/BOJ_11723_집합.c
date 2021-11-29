#include <stdio.h>
main() {
	int n, x, bit = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[7];
		scanf("%s", str);
		if (str[0] == 'a') {
			if (str[1] == 'd') {
				scanf("%d", &x);
				bit |= 1 << x;
			}
			else {
				bit |= (1 << 21) - 1;
			}
		}
		else if (str[0] == 'r') {
			scanf("%d", &x);
			bit &= ~(1 << x);
		}
		else if (str[0] == 'c') {
			scanf("%d", &x);
			if ((bit & 1 << x) != 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (str[0] == 't') {
			scanf("%d", &x);
			bit ^= 1 << x;
		}
		else {
			bit = 0;
		}
	}
}