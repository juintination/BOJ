#include <stdio.h>
int n, result = 0, com[101][101], visited[101], cnt[101];
void dfs(int idx) {
	visited[idx] = 1;
	for (int i = 0; i < cnt[idx]; i++) {
		if (!visited[com[idx][i]]) {
			result++;
			dfs(com[idx][i]);
		}
	}
}
main() {
	int m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		com[x][cnt[x]++] = y;
		com[y][cnt[y]++] = x;
	}
	dfs(1);
	printf("%d", result);
}