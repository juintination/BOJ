#include <stdio.h>
int fact(int n) {
	if (n <= 1) return 1;
	else return n * fact(n - 1);
}
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", fact(n) / (fact(n - k) * fact(k)));
}