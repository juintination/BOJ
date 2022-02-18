#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int func5(int num) {
	int cnt = 0;
	while (num >= 5) {
		cnt += (num / 5);
		num /= 5;
	}
	return cnt;
}
int func2(int num) {
	int cnt = 0;
	while (num >= 2) {
		cnt += (num / 2);
		num /= 2;
	}
	return cnt;
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int two = func2(n) - func2(n - m) - func2(m);
	int five = func5(n) - func5(n - m) - func5(m);
	printf("%d", math_min(two, five));
}