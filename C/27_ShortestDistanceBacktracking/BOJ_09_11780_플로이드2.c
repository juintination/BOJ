#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define math_min(a, b) a < b ? a : b
int** idxArr;
const int INF = INT_MAX / 2;
void floydWarshall(int** route, int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (route[i][j] > route[i][k] + route[k][j]) {
					route[i][j] = route[i][k] + route[k][j];
					idxArr[i][j] = idxArr[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", route[i][j] != INF ? route[i][j] : 0);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!idxArr[i][j]) {
				printf("0\n");
			}
			else {
				int* stack = (int*)malloc(sizeof(int) * n);
				int idx = -1, k = idxArr[i][j];
				stack[++idx] = j;
				while (i != k) {
					stack[++idx] = k;
					k = idxArr[i][k];
				}
				stack[++idx] = i;
				printf("%d ", idx + 1);
				while (idx >= 0) {
					printf("%d ", stack[idx--]);
				}
				printf("\n");
				free(stack);
			}
		}
	}
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int** route = (int**)malloc(sizeof(int*) * (n + 1));
	idxArr = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		route[i] = (int*)malloc(sizeof(int) * (n + 1));
		idxArr[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 1; j <= n; j++) {
			route[i][j] = INF;
			idxArr[i][j] = 0;
		}
		route[i][i] = 0;
	}
	int a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		route[a][b] = math_min(route[a][b], c);
		idxArr[a][b] = a;
	}
	floydWarshall(route, n);
}