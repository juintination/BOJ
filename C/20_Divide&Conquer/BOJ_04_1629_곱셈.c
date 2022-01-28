#include <stdio.h>
int c;
long long int cal(int a, int b) {
	if (b == 1) return a % c;
	long long int tmp = cal(a, b / 2);
	if (b % 2 == 1) {
		return (tmp * tmp % c) * a % c;
	}
	return tmp * tmp % c;
}
main() {
	int a, b;
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", cal(a, b));
}