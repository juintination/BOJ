#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int arr[10], cost[10][10], visited[10], n, min = 2147483647;
void dfs(int dpth) {
	if (dpth == n) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (cost[arr[i - 1]][arr[i]] != 0) {
				sum += cost[arr[i - 1]][arr[i]];
			}
			else return;
		}
		if (cost[arr[n - 1]][arr[0]] != 0) {
			sum += cost[arr[n - 1]][arr[0]];
		}
		else return;
		min = math_min(min, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[dpth] = i;
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &cost[i][j]);
		}
	}
	dfs(0);
	printf("%d", min);
}