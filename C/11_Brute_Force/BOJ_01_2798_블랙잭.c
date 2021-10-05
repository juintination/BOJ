#include <stdio.h>
main() {
	int n, m, card[100], max = 0, sum = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= m && sum > max) {
					max = sum;
				}
			}
		}
	}
	printf("%d", max);
}