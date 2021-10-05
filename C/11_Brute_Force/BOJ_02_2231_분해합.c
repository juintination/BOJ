#include <stdio.h>
main() {
	int n;
	char narr[8];
	scanf("%d", &n);
	int m = n, cnt = 0;
	while (m != 0) {
		m /= 10;
		cnt++;
	}
	int x, min = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		x = i;
		sum = i;
		int j = 0;
		while (x != 0) {
			narr[j] = x % 10;
			sum = sum + narr[j];
			x = x / 10;
			j++;
		}
		if (sum == n) {
			min = i;
			break;
		}
		sum = 0;
	}
	printf("%d", min);
}