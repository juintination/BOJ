#include <stdio.h>
main() {
	int sum = 0, first = 1;
	while (1) {
		int n;
		char c;
		scanf("%d%c", &n, &c);
		if (first) sum += n;
		else sum -= n;
		if (c == '+') continue;
		else if (c == '-') first = 0;
		else break;
	}
	printf("%d", sum);
}