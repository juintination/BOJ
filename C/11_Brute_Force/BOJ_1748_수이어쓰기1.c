#include <stdio.h>
int math_pow(int x, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
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
	int n, sum = 0;
	scanf("%d", &n);
	int len = length(n);
	for (int i = 0; i < len - 1; i++) {
		sum += (9 * math_pow(10, i) * (i + 1));
	}
	sum += (len * (n - math_pow(10, len - 1) + 1));
	printf("%d", sum);
}