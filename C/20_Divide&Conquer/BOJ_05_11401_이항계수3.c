#include <stdio.h>
const int p = 1000000007;
long long int pow(int a, int b) {
	if (b == 1) return a % p;
	long long int tmp = pow(a, b / 2);
	if (b % 2 == 1) {
		return (tmp * tmp % p) * a % p;
	}
	return tmp * tmp % p;
}
long long int factorial(long long int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1) % p;
}
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long int numerator = factorial(n);
	long long denominator = factorial(k) * factorial(n - k) % p;
	printf("%d", (numerator * pow(denominator, p - 2)) % p);
}