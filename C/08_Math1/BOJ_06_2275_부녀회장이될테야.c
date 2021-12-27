#include <stdio.h>
main() {
	int t, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	int apt[15][15];
	for (int i = 0; i < 15; i++) {
		apt[i][1] = 1;
		apt[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++) {
			apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}
	while (t--) {
		int k, n;
		scanf("%d %d", &k, &n);
		result[cnt++] = apt[k][n];
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}