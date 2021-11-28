#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, max = 0, arr[15][15];
void dfs(int dpth, int sum) {
	if (dpth == n) {
		max = math_max(max, sum);
		return;
	}
	if (dpth + arr[dpth][0] <= n) {
		dfs(dpth + arr[dpth][0], sum + arr[dpth][1]);
	}
	dfs(dpth + 1, sum);
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	dfs(0, 0);
	printf("%d", max);
}