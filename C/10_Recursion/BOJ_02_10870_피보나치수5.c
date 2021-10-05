#include <stdio.h>
int fibon(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibon(n - 1) + fibon(n - 2);
}
main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibon(n));
}