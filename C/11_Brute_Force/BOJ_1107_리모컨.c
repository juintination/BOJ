#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int math_abs(int n) {
	if (n < 0) {
		n = -n;
	}
	return n;
}
int length(int i) {
	int cnt = 0;
	while (1) {
		i /= 10;
		cnt++;
		if (i == 0) break;
	}
	return cnt;
}
main() {
	int n, m, broken[10];
	scanf("%d %d", &n, &m);
	if (m > 0) {
		while (m-- > 0) {
			int tmp;
			scanf("%d", &tmp);
			broken[tmp] = 1;
		}
	}
	int min = math_abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int ing = i;
		int len = length(i);
		int tst = 0;
		for (int j = 0; j < len; j++) {
			if (broken[ing % 10] == 1) {
				tst = !tst;
				break;
			}
			ing /= 10;
		}
		if (tst == 0) {
			int tmp = len + math_abs(n - i);
			min = math_min(tmp, min);
		}
	}
	printf("%d", min);
}