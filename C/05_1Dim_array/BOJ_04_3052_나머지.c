#include <stdio.h>
main() {
	int n[1000], m, cnt = 10;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (n[i] % 42 == n[j] % 42) {
				cnt--;
				break;
			}
		}
	}
	printf("%d", cnt);
}