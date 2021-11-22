#include <stdio.h>
int n, cnt = 0, com[101][101], visited[101];
void dfs(int dpth) {
	visited[dpth] = 1;
	for (int i = 1; i <= n; i++) {
		if (com[dpth][i] && !visited[i]) {
			cnt++;
			dfs(i);
		}
	}
}
main() {
	int m, x, y;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &x, &y);
		com[x][y] = 1;
		com[y][x] = 1;
	}
	dfs(1);
	printf("%d", cnt);
}