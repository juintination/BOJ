#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define math_min(a, b) a < b ? a : b
const int INF = INT_MAX / 2;
typedef struct {
	int teleport, r, c;
} point;
void floydWarshall(int** route, int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				route[i][j] = math_min(route[i][j], route[i][k] + route[k][j]);
			}
		}
	}
}
main() {
	int n, t;
	scanf("%d %d", &n, &t);
	int** route = (int**)malloc(sizeof(int*) * (n + 1));
	point* city = (point*)malloc(sizeof(point) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &city[i].teleport, &city[i].r, &city[i].c);
		route[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 1; j <= n; j++) {
			route[i][j] = INF;
		}
		route[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (city[i].teleport && city[j].teleport) {
				route[i][j] = route[j][i] = math_min(t, abs(city[i].r - city[j].r) + abs(city[i].c - city[j].c));
			}
			else {
				route[i][j] = abs(city[i].r - city[j].r) + abs(city[i].c - city[j].c);
			}
		}
	}
	floydWarshall(route, n);
	int m, a, b;
	scanf("%d", &m);
	int* result = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		result[i] = route[a][b];
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
	}
}