#include <stdio.h>
main() {
	int num[9], j, max = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num[i]);
		if (num[i] > max) {
			max = num[i];
			j = i;
		}
	}
	printf("%d\n%d", max, j + 1);
}