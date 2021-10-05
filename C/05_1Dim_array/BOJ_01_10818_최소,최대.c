#include <stdio.h>
int arr[1000000];
main() {
	int n, max = -1000000, min = 1000000;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int j = 0; j < n; j++) {
		if (arr[j] > max) {
			max = arr[j];
		}
	}
	for (int j = 0; j < n; j++) {
		if (arr[j] < min) {
			min = arr[j];
		}
	}
	printf("%d %d", min, max);
}