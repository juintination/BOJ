#include <stdio.h>
int w, h, arr[50][50], visited[50][50], cnt;
void dfs(int x, int y) {
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 , 1, 1, -1, -1 };
	int dy[] = { 0, -1, 0, 1 , -1, 1, 1, -1 };
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && arr[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}
main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				arr[i][j] = visited[i][j] = 0;
			}
		}
		printf("%d\n", cnt);
	}
}