#include <stdio.h>
int n, ivxl[] = { 1, 5, 10, 50 }, visited[1001], cnt = 0;
void dfs(int dpth, int idx, int sum) {
	if (dpth == n) {
		if (!visited[sum]) {
			visited[sum] = 1;
			cnt++;
		}
		return;
	}
	for (int i = idx; i < 4; i++) {
		dfs(dpth + 1, i, sum + ivxl[i]);
	}
}
main() {
	scanf("%d", &n);
	dfs(0, 0, 0);
	printf("%d", cnt);
}