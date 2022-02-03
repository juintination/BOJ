#include <stdio.h>
main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	int** a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	int** b = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		b[i] = (int*)malloc(sizeof(int) * k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	int** c = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(sizeof(int) * k);
		for (int j = 0; j < k; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}