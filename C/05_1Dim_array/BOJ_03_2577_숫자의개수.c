#include <stdio.h>
main() {
	int a, b, c, arr[9], result[10];
	scanf("%d %d %d", &a, &b, &c);
	long long int x = a * b * c;
	for (int i = 0; i < 10; i++) {
		result[i] = 0;
	}
	int z = 1;
	for (int i = 0; i < 9; i++) {
		arr[i] = x / z % 10;
		z *= 10;
		for (int j = 0; j < 10; j++) {
			if (arr[i] == j) {
				result[j]++;
			}
		}
	}
	int k = 8;
	while (1) {
		if (arr[k] == 0) {
			result[0]--;
			k--;
		}
		else break;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", result[i]);
	}
}