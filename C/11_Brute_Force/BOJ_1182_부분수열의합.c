#include <stdio.h>
main() {
	int n, s, arr[20], cnt = 0;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i & 1 << j) != 0) {
				sum += arr[j];
			}
		}
		if (sum == s) {
			cnt++;
		}
	}
	printf("%d", cnt);
}