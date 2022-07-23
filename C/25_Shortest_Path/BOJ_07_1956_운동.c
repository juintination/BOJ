#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define math_min(a, b) a < b ? a : b
const int INF = INT_MAX / 2;
int floydWarshall(int** route, int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				route[i][j] = math_min(route[i][j], route[i][k] + route[k][j]);
			}
		}
	}
	int min = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				min = math_min(min, route[i][j] + route[j][i]);
			}
		}
	}
	return min;
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int** route = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		route[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 1; j <= n; j++) {
			route[i][j] = INF;
		}
		route[i][i] = 0;
	}
	int a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		route[a][b] = math_min(route[a][b], c);
	}
	int min = floydWarshall(route, n);
	printf("%d", min != INF ? min : -1);
}