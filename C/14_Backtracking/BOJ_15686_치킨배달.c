#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define math_min(a, b) a < b ? a : b
int n, m, **arr, *visited, result = 2147483647, cnt1 = 0, cnt2 = 0;
typedef struct {
	int x, y;
} point;
point *home, *chicken;
void initVisited(int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
}
void dfs(int dpth, int idx) {
	if (dpth == m) {
		int sum = 0;
		for (int i = 0; i < cnt1; i++) {
			int min = 2147483647;
			for (int j = 0; j < cnt2; j++) {
				if (visited[j]) {
					int d = abs(home[i].x - chicken[j].x) + abs(home[i].y - chicken[j].y);
					min = math_min(min, d);
				}
			}
			sum += min;
		}
		result = math_min(result, sum);
		return;
	}
	for (int i = idx; i < cnt2; i++) {
		visited[i] = 1;
		dfs(dpth + 1, i + 1);
		visited[i] = 0;
	}
}
main() {
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(sizeof(int*) * n);
	home = (point*)malloc(sizeof(point) * (n * n));
	chicken = (point*)malloc(sizeof(point) * (n * n));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				home[cnt1].x = i;
				home[cnt1++].y = j;
			}
			else if (arr[i][j] == 2) {
				chicken[cnt2].x = i;
				chicken[cnt2++].y = j;
			}
		}
	}
	visited = (int*)malloc(sizeof(int) * cnt2);
	initVisited(cnt2);
	dfs(0, 0);
	printf("%d", result);
}