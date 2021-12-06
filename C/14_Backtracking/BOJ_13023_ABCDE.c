#include <stdio.h>
int n, m, arr[2000][2000], visited[2000], cnt[2000] = { 0 };
void dfs(int dpth, int idx) {
	if (dpth == 4) {
		printf("1");
		exit(0);
	}
	visited[idx] = 1;
	for (int i = 0; i < cnt[idx]; i++) {
		if (!visited[arr[idx][i]]) {
			dfs(dpth + 1, arr[idx][i]);
		}
	}
	visited[idx] = 0;
}
main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][cnt[x]++] = y;
		arr[y][cnt[y]++] = x;
	}
	for (int i = 0; i < n; i++) {
		dfs(0, i);
	}
	printf("0");
}