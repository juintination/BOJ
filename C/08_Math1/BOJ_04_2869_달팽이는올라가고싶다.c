#include <stdio.h>
main() {
	int a, b, v, cnt;
	scanf("%d %d %d", &a, &b, &v);
	cnt = (v - b) / (a - b);
	if ((v - b) % (a - b) != 0) {
		cnt++;
	}
	printf("%d", cnt);
}