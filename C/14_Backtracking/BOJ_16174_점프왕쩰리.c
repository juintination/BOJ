#include <stdio.h>
int n, tst = 0, jelly[64][64], visited[64][64];
void dfs(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		tst = 1;
		return;
	}
	int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };
	visited[x][y] = 1;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i] * jelly[x][y];
		int ny = y + dy[i] * jelly[x][y];
		if (nx < n && ny < n && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
main() {
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &jelly[i][j]);
		}
	}
	dfs(0, 0);
	if (tst) printf("HaruHaru");
	else printf("Hing");
}