#include <stdio.h>
main() {
	int n, m, cnt;
	cnt = 1;
	scanf("%d", &n);
	if (n < 10) {
		n = n * 10;
	}
	m = n;
	while (((n % 10) * 10) + (((n / 10) + (n % 10)) % 10) != m) {
		n = ((n % 10) * 10) + (((n / 10) + (n % 10)) % 10);
		cnt++;
	}
	printf("%d", cnt);
}