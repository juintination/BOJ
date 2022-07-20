#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define math_min(a, b) a < b ? a : b
typedef struct {
	int from, to, cost;
} point;
point* list;
int n, m;
int INF = INT_MAX;
long long int* min;
int bellmanFord() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			point bus = list[j];
			if (min[bus.from] == INF) continue;
			min[bus.to] = math_min(min[bus.to], min[bus.from] + bus.cost);
		}
	}
	for (int j = 0; j < m; j++) {
		point bus = list[j];
		if (min[bus.from] != INF && min[bus.to] > min[bus.from] + bus.cost) {
			return 1;
		}
	}
	return 0;
}
main() {
	scanf("%d %d", &n, &m);
	min = (long long int*)malloc(sizeof(long long int) * (n + 1));
	for (int i = 2; i <= n; i++) {
		min[i] = INF;
	}
	min[1] = 0;
	list = (point*)malloc(sizeof(point) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &list[i].from, &list[i].to, &list[i].cost);
	}
	if (bellmanFord()) {
		printf("-1");
	}
	else {
		for (int i = 2; i <= n; i++) {
			printf("%d\n", min[i] != INF ? min[i] : -1);
		}
	}
}