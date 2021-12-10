#include <stdio.h>
int n, m, arr[50][50], visited[50][50], cnt;
void dfs(int x, int y) {
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}
main() {
	int t, idx = 0;
	int* result = (int*)malloc(sizeof(int) * t);
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				arr[i][j] = visited[i][j] = 0;
			}
		}
		while (k--) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[y][x] = 1;
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		result[idx++] = cnt;
	}
	for (int i = 0; i < idx; i++) {
		printf("%d\n", result[i]);
	}
}