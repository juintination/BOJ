#include <stdio.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, m, max, tetromino[500][500], visited[500][500];
void dfs(int x, int y, int dpth, int sum) {
	if (dpth == 4) {
		max = math_max(max, sum);
		return;
	}
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
			visited[nx][ny] = 1;
			dfs(nx, ny, dpth + 1, sum + tetromino[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}
void mountaion(int x, int y) {
	int wing = 4, min = 1001;
	int sum = tetromino[x][y];
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		if (wing <= 2) return;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			min = math_min(min, tetromino[nx][ny]);
			sum += tetromino[nx][ny];
		}
		else wing--;
	}
	if (wing == 4) sum -= min;
	max = math_max(max, sum);
}
main() {
	scanf("%d %d", &n, &m);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			scanf("%d", &tetromino[i][j]);
		}
	}
	max = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			dfs(i, j, 0, 0);
			mountaion(i, j);
		}
	}
	printf("%d", max);
}