#include <stdio.h>
int tile(int n) {
	int f0 = 1;
	int f1 = 1;
	int sum = 1;
	for (int i = 1; i < n; i++) {
		sum = (f1 + f0) % 15746;
		f0 = f1;
		f1 = sum;
	}
	return sum;
}
main() {
	int n;
	scanf("%d", &n);
	printf("%d", tile(n));
}