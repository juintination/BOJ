#include <stdio.h>
int n, m, arr[1001][1001], visited[1001], cnt[1001] = { 0 };
void dfs(int idx) {
	visited[idx] = 1;
	for (int i = 0; i < cnt[idx]; i++) {
		if (!visited[arr[idx][i]]) {
			dfs(arr[idx][i]);
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][cnt[x]++] = y;
		arr[y][cnt[y]++] = x;
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			result++;
		}
	}
	printf("%d", result);
}